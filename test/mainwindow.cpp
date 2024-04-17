#include "mainwindow.h"
#include "CanvasWidget.h"
#include "ui_mainwindow.h"
#include "Parser.h"
#include <QLabel>
#include <QPixmap>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load and apply the stylesheet
    QFile styleFile(":/stylesheets/stylesheet.css"); // Assuming the stylesheet file is added to the Qt resources
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    this->setStyleSheet(styleSheet);

    // Create a layout for the drawingAreaGroupBox
    QVBoxLayout *drawingAreaLayout = new QVBoxLayout(ui->drawingAreaGroupBox);
    drawingAreaLayout->setContentsMargins(0, 0, 0, 0);

    canvasWidget = new CanvasWidget(this);
    drawingAreaLayout->addWidget(canvasWidget);

    treeModelWrapper.connectSignals(this);

    QAction *createCreasePatternAction = new QAction(tr("Create Crease Pattern"), this);
    connect(createCreasePatternAction, &QAction::triggered, this, &MainWindow::onCreateCreasePatternClicked);
    ui->menuCreate_Crease_Pattern->addAction(createCreasePatternAction);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTreeUpdated()
{
    qDebug() << "Tree updated";
}

void MainWindow::onCreateCreasePatternClicked()
{
    qDebug() << "Create Crease Pattern clicked";

    // Parse points and edges from the canvas
    std::vector<std::pair<double, double>> nodePositions = Parser::parsePointsAndEdges(canvasWidget->getPoints(), canvasWidget->getEdges());

    // Create tree from parsed node positions
    tmTree *tree = treeModelWrapper.createTreeFromList(nodePositions);

    // Check if the tree is valid
    if (tree != nullptr) {
        qDebug() << "Created a valid tree";

        // Build tree polygons
        treeModelWrapper.buildTreePolys();

        // Check if the tree is optimized
        if (treeModelWrapper.isTreeOptimized()) {
            qDebug() << "Tree is optimized";

            // Build crease pattern
            treeModelWrapper.buildCreasePattern();

            // Check if the crease pattern is valid
            if (treeModelWrapper.hasFullCreasePattern()) {
                qDebug() << "Crease pattern is valid";
            } else {
                qDebug() << "Crease pattern is not valid";
            }
        } else {
            qDebug() << "Tree is not optimized";
        }
    } else {
        qDebug() << "Failed to create a valid tree";
    }
}

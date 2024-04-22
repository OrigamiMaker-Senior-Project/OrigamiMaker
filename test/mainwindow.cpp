#include "mainwindow.h"
#include "CanvasWidget.h"
#include "ui_mainwindow.h"
#include "Parser.h"
#include <QLabel>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include "TreeModelWrapper.h"
#include <QVBoxLayout>
#include <QPushButton>

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

    int canvasSize = 650;
    canvasWidget->setFixedSize(canvasSize, canvasSize);

    treeModelWrapper.connectSignals(this);

    //treeModelWrapper.runTests();

    QAction *createCreasePatternAction = new QAction(tr("Create Crease Pattern"), this);
    connect(createCreasePatternAction, &QAction::triggered, this, &MainWindow::onCreateCreasePatternClicked);
    ui->menubar->addAction(createCreasePatternAction);

    QAction *createDemoButton = new QAction(tr("Create Demo"), this);
    connect(createDemoButton, &QAction::triggered, this, &MainWindow::onCreateDemoClicked);
    ui->menubar->addAction(createDemoButton);

    // Add "Create Demo Crease Pattern" button
    QAction *createDemoCreasePatternButton = new QAction(tr("Create Demo Crease Pattern"), this);
    connect(createDemoCreasePatternButton, &QAction::triggered, this, &MainWindow::onCreateDemoCreasePatternClicked);
    ui->menubar->addAction(createDemoCreasePatternButton);

    creasePatternDialog = new QDialog(this);
    creasePatternDialog->setWindowTitle("Crease Pattern");
    creasePatternDialog->setFixedSize(500, 500);



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
    if (tree != nullptr) {
        treeModelWrapper.setTreeScale(); // Set the tree scale to 1 by 1

    }
    // Check if the tree is valid
    if (tree != nullptr) {
        qDebug() << "Created a valid tree";

        // Build tree polygons
        treeModelWrapper.buildTreePolys();

        // Optimize the tree
        treeModelWrapper.optimizeTree();

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

void MainWindow::onCreateDemoClicked()
{
    qDebug() << "Create Demo clicked";
    canvasWidget->createDemoTree();
}

void MainWindow::onCreateDemoCreasePatternClicked()
{
    qDebug() << "Create Demo Crease Pattern clicked";
    canvasWidget->drawDemoCreasePattern();


    QVBoxLayout *dialogLayout = new QVBoxLayout(creasePatternDialog);

    creasePatternLabel = new QLabel(creasePatternDialog);
    creasePatternLabel->setScaledContents(true);
    dialogLayout->addWidget(creasePatternLabel);

    QPushButton *closeButton = new QPushButton("Close", creasePatternDialog);
    connect(closeButton, &QPushButton::clicked, creasePatternDialog, &QDialog::close);
    dialogLayout->addWidget(closeButton);
}

void MainWindow::showCreasePatternDialog(const QPixmap &pixmap)
{
    creasePatternLabel->setPixmap(pixmap);
    creasePatternDialog->exec();
}

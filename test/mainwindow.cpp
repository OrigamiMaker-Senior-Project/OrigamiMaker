#include "mainwindow.h"
#include "CanvasWidget.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QFile>

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


    // Create the canvas widget and add it to a specific section of the main window
    canvasWidget = new CanvasWidget(this);
    // setCentralWidget(canvasWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

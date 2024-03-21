#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvaswidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the CanvasWidget to the main window
    CanvasWidget *canvas = findChild<CanvasWidget *>("widget");
    if (canvas) {
        // You can set up any necessary connections or initializations for the canvas here
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
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

    ui->hideDropDown->hide();
    ui->foldedImageGroupBox->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_hideFoldedImageButton_clicked()
{
    ui->foldedImageGroupBox->hide();
    ui->hideDropDown->hide();
    ui->showDropDown->show();
}


void MainWindow::on_showFoldedImageButton_clicked()
{
    ui->foldedImageGroupBox->show();
    ui->hideDropDown->show();
    ui->showDropDown->hide();
}


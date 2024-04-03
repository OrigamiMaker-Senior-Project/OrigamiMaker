#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CanvasWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showFoldedFormButton_clicked();

    void on_hideFoldedFormButton_clicked();

private:
    Ui::MainWindow *ui;
    CanvasWidget *canvasWidget;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CanvasWidget.h"
#include "TreeModelWrapper.h"

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


public slots:
    void onTreeUpdated();
    void onCreateCreasePatternClicked();

private:
    Ui::MainWindow *ui;
    CanvasWidget *canvasWidget;
    TreeModelWrapper treeModelWrapper;
};
#endif // MAINWINDOW_H

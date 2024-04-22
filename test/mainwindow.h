#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CanvasWidget.h"
#include "TreeModelWrapper.h"
#include <QLabel>
#include <QDialog>

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
    void onCreateDemoClicked();
    void onCreateDemoCreasePatternClicked();
    void showCreasePatternDialog(const QPixmap &pixmap);

private:
    Ui::MainWindow *ui;
    CanvasWidget *canvasWidget;
    TreeModelWrapper treeModelWrapper;
    QDialog *creasePatternDialog;
    QLabel *creasePatternLabel;
};

#endif // MAINWINDOW_H

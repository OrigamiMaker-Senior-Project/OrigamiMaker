#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>

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

    void on_hideFoldedImageButton_clicked();

    void on_showFoldedImageButton_clicked();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H

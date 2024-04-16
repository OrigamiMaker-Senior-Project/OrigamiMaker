/*#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Run your application
    MainWindow w;
    w.show();
    return a.exec();
}

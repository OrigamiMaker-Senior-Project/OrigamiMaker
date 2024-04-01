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

    // /*// Load the style sheet file
    // QFile styleFile("style.css"); // Path to your style sheet file
    // styleFile.open(QFile::ReadOnly);

    // // Create a QTextStream to read the file
    // QTextStream in(&styleFile);

    // // Read the content of the file
    // QString cssContent = in.readAll();

    // // Close the file
    // styleFile.close();

    // if(!styleFile.isOpen()){
    //     std::cout<<"problem";

    // }

    // // Apply the style sheet to the application
    // QString styleSheet = QLatin1String(styleFile.readAll());
    // a.setStyleSheet(styleSheet);
    // */

    // QFile file(":/otherfiles/stylesheet.css");

    // // Check if the file can be opened
    // if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //     qDebug() << "Error: Could not open file";
    //     return 1; // Return error code if file cannot be opened
    // }

    // // Create a QTextStream to read the file
    // QTextStream in(&file);

    // // Read the content of the file
    // QString cssContent = in.readAll();

    // // Close the file
    // file.close();

    // // Print the CSS content
    // qDebug() << "CSS Content:";
    // qDebug().noquote() << cssContent; // Print without additional formatting
    // Run your application
    MainWindow w;
    w.show();
    return a.exec();
}

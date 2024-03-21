/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <canvaswidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QGroupBox *groupBox_5;
    QRadioButton *radioButton;
    QLabel *label_11;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    CanvasWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 100, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(100, 0, 100, 32));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(300, 0, 100, 32));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(200, 0, 100, 32));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(629, 0, 151, 32));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 801, 31));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(460, 30, 801, 31));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(490, 30, 311, 241));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(460, 30, 801, 31));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 40, 58, 21));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(60, 40, 91, 21));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(60, 70, 91, 21));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 70, 58, 21));
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(60, 100, 91, 21));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(37, 100, 31, 21));
        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(60, 130, 91, 21));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 130, 58, 21));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(160, 40, 58, 21));
        lineEdit_8 = new QLineEdit(groupBox_3);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(210, 40, 91, 21));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(187, 100, 31, 21));
        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(210, 100, 91, 21));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 170, 71, 21));
        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(10, 210, 91, 21));
        lineEdit_11 = new QLineEdit(groupBox_3);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(150, 210, 91, 21));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(490, 270, 301, 241));
        radioButton = new QRadioButton(groupBox_5);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(10, 60, 121, 20));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 30, 141, 21));
        radioButton_2 = new QRadioButton(groupBox_5);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(10, 80, 99, 20));
        radioButton_3 = new QRadioButton(groupBox_5);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(10, 120, 99, 20));
        radioButton_4 = new QRadioButton(groupBox_5);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(10, 100, 99, 20));
        widget = new CanvasWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 40, 481, 461));
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        groupBox_3->raise();
        groupBox_5->raise();
        widget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Build Crease Pattern", nullptr));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Width =", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Scale =", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X =", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Angle =", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Width =", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y =", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Symmetry", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "Diagonal", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Conditions", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Symmetry Line", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Node(s) Fixed To...", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Paper Edge", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Corner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Ctrl_N;
    QAction *actionOpen_Ctrl_O;
    QAction *actionClose_Ctrl_S;
    QAction *actionSave_Ctrl_S;
    QAction *actionSave_As_Ctrl_Alt_S;
    QAction *actionRevert;
    QAction *actionPrint_Ctrl_P;
    QAction *actionPrint_Setup;
    QAction *actionPrint_Preview_Ctrl_Alt_P;
    QAction *actionPreferences;
    QAction *actionExit_Alt_X;
    QAction *actionUndo_Drag_Ctrl_Z;
    QAction *actionRedo_Ctrl_Y;
    QAction *actionCut_Ctrl_X;
    QAction *actionCopy_Ctrl_C;
    QAction *actionPaste_Ctrl_V;
    QAction *actionClear;
    QAction *actionShow_Hide_Inspector_Ctrl_I;
    QAction *actionShow_Hide_View_Settings_Ctrl_G;
    QAction *actionShow_Hide_Folded_Form_Ctrl_F;
    QAction *actionTree_View_Ctrl_Shift_T;
    QAction *actionDesign_View_Ctrl_Shift_D;
    QAction *actionCreases_View_Ctrl_Shift_C;
    QAction *actionPlan_View_Ctrl_Shift_P;
    QAction *actionFit_to_Screen_Ctrl_Shift_F;
    QAction *actionFit_to_Width_Ctrl_Shift_W;
    QAction *actionFit_to_Height_Ctrl_Shift_H;
    QAction *actionSet_Paper_Size_Ctrl_Shift_Y;
    QAction *actionTreeMaker_Help_F1;
    QAction *actionAbout_TreeMaker;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *drawingAreaGroupBox;
    QGroupBox *sideMenuGroupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 712);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 500));
        actionNew_Ctrl_N = new QAction(MainWindow);
        actionNew_Ctrl_N->setObjectName("actionNew_Ctrl_N");
        actionOpen_Ctrl_O = new QAction(MainWindow);
        actionOpen_Ctrl_O->setObjectName("actionOpen_Ctrl_O");
        actionClose_Ctrl_S = new QAction(MainWindow);
        actionClose_Ctrl_S->setObjectName("actionClose_Ctrl_S");
        actionSave_Ctrl_S = new QAction(MainWindow);
        actionSave_Ctrl_S->setObjectName("actionSave_Ctrl_S");
        actionSave_As_Ctrl_Alt_S = new QAction(MainWindow);
        actionSave_As_Ctrl_Alt_S->setObjectName("actionSave_As_Ctrl_Alt_S");
        actionRevert = new QAction(MainWindow);
        actionRevert->setObjectName("actionRevert");
        actionPrint_Ctrl_P = new QAction(MainWindow);
        actionPrint_Ctrl_P->setObjectName("actionPrint_Ctrl_P");
        actionPrint_Setup = new QAction(MainWindow);
        actionPrint_Setup->setObjectName("actionPrint_Setup");
        actionPrint_Preview_Ctrl_Alt_P = new QAction(MainWindow);
        actionPrint_Preview_Ctrl_Alt_P->setObjectName("actionPrint_Preview_Ctrl_Alt_P");
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName("actionPreferences");
        actionExit_Alt_X = new QAction(MainWindow);
        actionExit_Alt_X->setObjectName("actionExit_Alt_X");
        actionUndo_Drag_Ctrl_Z = new QAction(MainWindow);
        actionUndo_Drag_Ctrl_Z->setObjectName("actionUndo_Drag_Ctrl_Z");
        actionRedo_Ctrl_Y = new QAction(MainWindow);
        actionRedo_Ctrl_Y->setObjectName("actionRedo_Ctrl_Y");
        actionCut_Ctrl_X = new QAction(MainWindow);
        actionCut_Ctrl_X->setObjectName("actionCut_Ctrl_X");
        actionCopy_Ctrl_C = new QAction(MainWindow);
        actionCopy_Ctrl_C->setObjectName("actionCopy_Ctrl_C");
        actionPaste_Ctrl_V = new QAction(MainWindow);
        actionPaste_Ctrl_V->setObjectName("actionPaste_Ctrl_V");
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        actionShow_Hide_Inspector_Ctrl_I = new QAction(MainWindow);
        actionShow_Hide_Inspector_Ctrl_I->setObjectName("actionShow_Hide_Inspector_Ctrl_I");
        actionShow_Hide_View_Settings_Ctrl_G = new QAction(MainWindow);
        actionShow_Hide_View_Settings_Ctrl_G->setObjectName("actionShow_Hide_View_Settings_Ctrl_G");
        actionShow_Hide_Folded_Form_Ctrl_F = new QAction(MainWindow);
        actionShow_Hide_Folded_Form_Ctrl_F->setObjectName("actionShow_Hide_Folded_Form_Ctrl_F");
        actionTree_View_Ctrl_Shift_T = new QAction(MainWindow);
        actionTree_View_Ctrl_Shift_T->setObjectName("actionTree_View_Ctrl_Shift_T");
        actionDesign_View_Ctrl_Shift_D = new QAction(MainWindow);
        actionDesign_View_Ctrl_Shift_D->setObjectName("actionDesign_View_Ctrl_Shift_D");
        actionCreases_View_Ctrl_Shift_C = new QAction(MainWindow);
        actionCreases_View_Ctrl_Shift_C->setObjectName("actionCreases_View_Ctrl_Shift_C");
        actionPlan_View_Ctrl_Shift_P = new QAction(MainWindow);
        actionPlan_View_Ctrl_Shift_P->setObjectName("actionPlan_View_Ctrl_Shift_P");
        actionFit_to_Screen_Ctrl_Shift_F = new QAction(MainWindow);
        actionFit_to_Screen_Ctrl_Shift_F->setObjectName("actionFit_to_Screen_Ctrl_Shift_F");
        actionFit_to_Width_Ctrl_Shift_W = new QAction(MainWindow);
        actionFit_to_Width_Ctrl_Shift_W->setObjectName("actionFit_to_Width_Ctrl_Shift_W");
        actionFit_to_Height_Ctrl_Shift_H = new QAction(MainWindow);
        actionFit_to_Height_Ctrl_Shift_H->setObjectName("actionFit_to_Height_Ctrl_Shift_H");
        actionSet_Paper_Size_Ctrl_Shift_Y = new QAction(MainWindow);
        actionSet_Paper_Size_Ctrl_Shift_Y->setObjectName("actionSet_Paper_Size_Ctrl_Shift_Y");
        actionTreeMaker_Help_F1 = new QAction(MainWindow);
        actionTreeMaker_Help_F1->setObjectName("actionTreeMaker_Help_F1");
        actionAbout_TreeMaker = new QAction(MainWindow);
        actionAbout_TreeMaker->setObjectName("actionAbout_TreeMaker");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        drawingAreaGroupBox = new QGroupBox(centralwidget);
        drawingAreaGroupBox->setObjectName("drawingAreaGroupBox");
        sizePolicy.setHeightForWidth(drawingAreaGroupBox->sizePolicy().hasHeightForWidth());
        drawingAreaGroupBox->setSizePolicy(sizePolicy);
        drawingAreaGroupBox->setMinimumSize(QSize(650, 650));

        gridLayout_4->addWidget(drawingAreaGroupBox, 0, 0, 1, 1);

        sideMenuGroupBox = new QGroupBox(centralwidget);
        sideMenuGroupBox->setObjectName("sideMenuGroupBox");
        sizePolicy.setHeightForWidth(sideMenuGroupBox->sizePolicy().hasHeightForWidth());
        sideMenuGroupBox->setSizePolicy(sizePolicy);
        sideMenuGroupBox->setMinimumSize(QSize(322, 0));
        sideMenuGroupBox->setStyleSheet(QString::fromUtf8(""));
        sideMenuGroupBox->setFlat(false);
        sideMenuGroupBox->setCheckable(false);
        label = new QLabel(sideMenuGroupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 281, 51));
        label_2 = new QLabel(sideMenuGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 260, 291, 31));
        label_3 = new QLabel(sideMenuGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 150, 291, 41));
        label_4 = new QLabel(sideMenuGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 180, 281, 31));
        label_5 = new QLabel(sideMenuGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 60, 281, 31));
        label_6 = new QLabel(sideMenuGroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 90, 231, 41));
        label_7 = new QLabel(sideMenuGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 320, 231, 41));
        label_8 = new QLabel(sideMenuGroupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 290, 281, 31));
        label_9 = new QLabel(sideMenuGroupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 200, 281, 41));
        label_10 = new QLabel(sideMenuGroupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 380, 291, 31));
        label_11 = new QLabel(sideMenuGroupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 400, 291, 51));

        gridLayout_4->addWidget(sideMenuGroupBox, 0, 5, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Ctrl_N);
        menuFile->addAction(actionOpen_Ctrl_O);
        menuFile->addAction(actionClose_Ctrl_S);
        menuFile->addAction(actionSave_Ctrl_S);
        menuFile->addAction(actionSave_As_Ctrl_Alt_S);
        menuFile->addAction(actionRevert);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint_Ctrl_P);
        menuFile->addAction(actionPrint_Setup);
        menuFile->addAction(actionPrint_Preview_Ctrl_Alt_P);
        menuFile->addAction(actionPreferences);
        menuFile->addAction(actionExit_Alt_X);
        menuEdit->addAction(actionUndo_Drag_Ctrl_Z);
        menuEdit->addAction(actionRedo_Ctrl_Y);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut_Ctrl_X);
        menuEdit->addAction(actionCopy_Ctrl_C);
        menuEdit->addAction(actionPaste_Ctrl_V);
        menuEdit->addAction(actionClear);
        menuEdit->addSeparator();
        menuView->addAction(actionFit_to_Screen_Ctrl_Shift_F);
        menuView->addAction(actionFit_to_Width_Ctrl_Shift_W);
        menuView->addAction(actionFit_to_Height_Ctrl_Shift_H);
        menuView->addAction(actionSet_Paper_Size_Ctrl_Shift_Y);
        menuHelp->addAction(actionTreeMaker_Help_F1);
        menuHelp->addAction(actionAbout_TreeMaker);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Ctrl_N->setText(QCoreApplication::translate("MainWindow", "New (Ctrl+N)", nullptr));
        actionOpen_Ctrl_O->setText(QCoreApplication::translate("MainWindow", "Open (Ctrl+O)", nullptr));
        actionClose_Ctrl_S->setText(QCoreApplication::translate("MainWindow", "Close (Ctrl+W)", nullptr));
        actionSave_Ctrl_S->setText(QCoreApplication::translate("MainWindow", "Save (Ctrl+S)", nullptr));
        actionSave_As_Ctrl_Alt_S->setText(QCoreApplication::translate("MainWindow", "Save As (Ctrl+Alt+S)", nullptr));
        actionRevert->setText(QCoreApplication::translate("MainWindow", "Revert", nullptr));
        actionPrint_Ctrl_P->setText(QCoreApplication::translate("MainWindow", "Print (Ctrl+P)", nullptr));
        actionPrint_Setup->setText(QCoreApplication::translate("MainWindow", "Print Setup", nullptr));
        actionPrint_Preview_Ctrl_Alt_P->setText(QCoreApplication::translate("MainWindow", "Print Preview (Ctrl+Alt+P)", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWindow", "Preferences", nullptr));
        actionExit_Alt_X->setText(QCoreApplication::translate("MainWindow", "Exit (Alt+X)", nullptr));
        actionUndo_Drag_Ctrl_Z->setText(QCoreApplication::translate("MainWindow", "Undo Drag (Ctrl+Z)", nullptr));
        actionRedo_Ctrl_Y->setText(QCoreApplication::translate("MainWindow", "Redo (Ctrl+Y)", nullptr));
        actionCut_Ctrl_X->setText(QCoreApplication::translate("MainWindow", "Cut (Ctrl+X)", nullptr));
        actionCopy_Ctrl_C->setText(QCoreApplication::translate("MainWindow", "Copy (Ctrl+C)", nullptr));
        actionPaste_Ctrl_V->setText(QCoreApplication::translate("MainWindow", "Paste (Ctrl+V)", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionShow_Hide_Inspector_Ctrl_I->setText(QCoreApplication::translate("MainWindow", "Show/Hide Inspector (Ctrl+I)", nullptr));
        actionShow_Hide_View_Settings_Ctrl_G->setText(QCoreApplication::translate("MainWindow", "Show/Hide View Settings (Ctrl+G)", nullptr));
        actionShow_Hide_Folded_Form_Ctrl_F->setText(QCoreApplication::translate("MainWindow", "Show/Hide Folded Form (Ctrl+F)", nullptr));
        actionTree_View_Ctrl_Shift_T->setText(QCoreApplication::translate("MainWindow", "Tree View (Ctrl+Shift+T)", nullptr));
        actionDesign_View_Ctrl_Shift_D->setText(QCoreApplication::translate("MainWindow", "Design View (Ctrl+Shift+D)", nullptr));
        actionCreases_View_Ctrl_Shift_C->setText(QCoreApplication::translate("MainWindow", "Creases View (Ctrl+Shift+C)", nullptr));
        actionPlan_View_Ctrl_Shift_P->setText(QCoreApplication::translate("MainWindow", "Plan View (Ctrl+Shift+P)", nullptr));
        actionFit_to_Screen_Ctrl_Shift_F->setText(QCoreApplication::translate("MainWindow", "Fit to Screen (Ctrl+Shift+F)", nullptr));
        actionFit_to_Width_Ctrl_Shift_W->setText(QCoreApplication::translate("MainWindow", "Fit to Width (Ctrl+Shift+W)", nullptr));
        actionFit_to_Height_Ctrl_Shift_H->setText(QCoreApplication::translate("MainWindow", "Fit to Height (Ctrl+Shift+H)", nullptr));
        actionSet_Paper_Size_Ctrl_Shift_Y->setText(QCoreApplication::translate("MainWindow", "Set Paper Size (Ctrl+Shift+Y)", nullptr));
        actionTreeMaker_Help_F1->setText(QCoreApplication::translate("MainWindow", "TreeMaker Help (F1)", nullptr));
        actionAbout_TreeMaker->setText(QCoreApplication::translate("MainWindow", "About TreeMaker", nullptr));
        drawingAreaGroupBox->setTitle(QString());
        sideMenuGroupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; text-decoration: underline;\">How to Use the Canvas</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Click and release without </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Double-click to move nodes:</span></p><p><br/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Press the node then release and</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Press and drag to create</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">new nodes and edges</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">It will be highlighted blue</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">dragging to select a node:</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">quickly press and drag the node</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Select a node then press the </span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">delete key to delete a node</span></p></body></html>", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

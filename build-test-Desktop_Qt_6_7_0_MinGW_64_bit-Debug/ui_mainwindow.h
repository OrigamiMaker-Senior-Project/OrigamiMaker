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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "CanvasWidget.h"

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
    QGroupBox *sideMenuGroupBox;
    QLabel *label_inspector;
    QScrollArea *inspectorScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout;
    QLineEdit *input_width;
    QLineEdit *input_Y;
    QLabel *label_symmetry;
    QLabel *label_scale;
    QLabel *label_width;
    QLineEdit *input_X;
    QLineEdit *input_scale;
    QLabel *label_X;
    QLabel *label_Y;
    QLabel *label_height;
    QLineEdit *input_height;
    QLabel *label_angle;
    QLineEdit *input_angle;
    QRadioButton *toggle_linear;
    QRadioButton *toggle_diagonal;
    QScrollArea *conditionsScrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox;
    QLabel *label_19;
    QCheckBox *checkBox_8;
    QLabel *label_2;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_2;
    QLabel *label_18;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_4;
    QScrollArea *viewSettingsScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_circles;
    QCheckBox *checkBox_indicies;
    QCheckBox *checkBox_leaf;
    QCheckBox *checkBox_branch;
    QRadioButton *crease_view;
    QCheckBox *checkBox_nodes;
    QRadioButton *plan_view;
    QCheckBox *checkBox_labels;
    QCheckBox *checkBox_sub;
    QCheckBox *checkBox_coordinates;
    QCheckBox *checkBox_dots;
    QCheckBox *checkBox_elevation;
    QRadioButton *tree_view;
    QRadioButton *design_view;
    QLabel *label_conditions;
    QLabel *label_view_settings;
    QGroupBox *drawingAreaGroupBox;
    CanvasWidget *canvas;
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
        MainWindow->resize(1000, 643);
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
        sideMenuGroupBox = new QGroupBox(centralwidget);
        sideMenuGroupBox->setObjectName("sideMenuGroupBox");
        sizePolicy.setHeightForWidth(sideMenuGroupBox->sizePolicy().hasHeightForWidth());
        sideMenuGroupBox->setSizePolicy(sizePolicy);
        sideMenuGroupBox->setMinimumSize(QSize(322, 0));
        sideMenuGroupBox->setFlat(false);
        sideMenuGroupBox->setCheckable(false);
        label_inspector = new QLabel(sideMenuGroupBox);
        label_inspector->setObjectName("label_inspector");
        label_inspector->setGeometry(QRect(10, 10, 121, 20));
        inspectorScrollArea = new QScrollArea(sideMenuGroupBox);
        inspectorScrollArea->setObjectName("inspectorScrollArea");
        inspectorScrollArea->setEnabled(true);
        inspectorScrollArea->setGeometry(QRect(0, 30, 321, 161));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inspectorScrollArea->sizePolicy().hasHeightForWidth());
        inspectorScrollArea->setSizePolicy(sizePolicy1);
        inspectorScrollArea->setMaximumSize(QSize(16777215, 200));
        inspectorScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 328, 145));
        gridLayout = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout->setObjectName("gridLayout");
        input_width = new QLineEdit(scrollAreaWidgetContents_2);
        input_width->setObjectName("input_width");
        input_width->setMaximumSize(QSize(64, 64));

        gridLayout->addWidget(input_width, 0, 2, 1, 1);

        input_Y = new QLineEdit(scrollAreaWidgetContents_2);
        input_Y->setObjectName("input_Y");
        input_Y->setMaximumSize(QSize(64, 64));

        gridLayout->addWidget(input_Y, 4, 4, 1, 1);

        label_symmetry = new QLabel(scrollAreaWidgetContents_2);
        label_symmetry->setObjectName("label_symmetry");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_symmetry->sizePolicy().hasHeightForWidth());
        label_symmetry->setSizePolicy(sizePolicy2);
        label_symmetry->setMaximumSize(QSize(128, 128));

        gridLayout->addWidget(label_symmetry, 9, 0, 1, 1);

        label_scale = new QLabel(scrollAreaWidgetContents_2);
        label_scale->setObjectName("label_scale");
        sizePolicy2.setHeightForWidth(label_scale->sizePolicy().hasHeightForWidth());
        label_scale->setSizePolicy(sizePolicy2);
        label_scale->setMinimumSize(QSize(16, 16));
        label_scale->setMaximumSize(QSize(128, 128));

        gridLayout->addWidget(label_scale, 2, 0, 1, 1);

        label_width = new QLabel(scrollAreaWidgetContents_2);
        label_width->setObjectName("label_width");
        label_width->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_width->sizePolicy().hasHeightForWidth());
        label_width->setSizePolicy(sizePolicy2);
        label_width->setMaximumSize(QSize(128, 128));

        gridLayout->addWidget(label_width, 0, 0, 1, 1);

        input_X = new QLineEdit(scrollAreaWidgetContents_2);
        input_X->setObjectName("input_X");
        input_X->setMaximumSize(QSize(64, 64));

        gridLayout->addWidget(input_X, 4, 2, 1, 1);

        input_scale = new QLineEdit(scrollAreaWidgetContents_2);
        input_scale->setObjectName("input_scale");
        input_scale->setMaximumSize(QSize(64, 64));

        gridLayout->addWidget(input_scale, 2, 2, 1, 1);

        label_X = new QLabel(scrollAreaWidgetContents_2);
        label_X->setObjectName("label_X");
        sizePolicy2.setHeightForWidth(label_X->sizePolicy().hasHeightForWidth());
        label_X->setSizePolicy(sizePolicy2);
        label_X->setMaximumSize(QSize(128, 128));
        label_X->setIndent(-2);

        gridLayout->addWidget(label_X, 4, 0, 1, 1);

        label_Y = new QLabel(scrollAreaWidgetContents_2);
        label_Y->setObjectName("label_Y");

        gridLayout->addWidget(label_Y, 4, 3, 1, 1);

        label_height = new QLabel(scrollAreaWidgetContents_2);
        label_height->setObjectName("label_height");

        gridLayout->addWidget(label_height, 0, 3, 1, 1);

        input_height = new QLineEdit(scrollAreaWidgetContents_2);
        input_height->setObjectName("input_height");
        input_height->setMaximumSize(QSize(64, 64));

        gridLayout->addWidget(input_height, 0, 4, 1, 1);

        label_angle = new QLabel(scrollAreaWidgetContents_2);
        label_angle->setObjectName("label_angle");
        sizePolicy2.setHeightForWidth(label_angle->sizePolicy().hasHeightForWidth());
        label_angle->setSizePolicy(sizePolicy2);
        label_angle->setMaximumSize(QSize(128, 128));

        gridLayout->addWidget(label_angle, 2, 3, 1, 1);

        input_angle = new QLineEdit(scrollAreaWidgetContents_2);
        input_angle->setObjectName("input_angle");
        input_angle->setMaximumSize(QSize(64, 64));

        gridLayout->addWidget(input_angle, 2, 4, 1, 1);

        toggle_linear = new QRadioButton(scrollAreaWidgetContents_2);
        toggle_linear->setObjectName("toggle_linear");

        gridLayout->addWidget(toggle_linear, 9, 2, 1, 1);

        toggle_diagonal = new QRadioButton(scrollAreaWidgetContents_2);
        toggle_diagonal->setObjectName("toggle_diagonal");

        gridLayout->addWidget(toggle_diagonal, 9, 3, 1, 1);

        inspectorScrollArea->setWidget(scrollAreaWidgetContents_2);
        conditionsScrollArea = new QScrollArea(sideMenuGroupBox);
        conditionsScrollArea->setObjectName("conditionsScrollArea");
        conditionsScrollArea->setGeometry(QRect(0, 220, 321, 181));
        conditionsScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, -258, 298, 437));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        checkBox_10 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_10->setObjectName("checkBox_10");

        gridLayout_2->addWidget(checkBox_10, 15, 0, 1, 1);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName("checkBox");

        gridLayout_2->addWidget(checkBox, 9, 0, 1, 1);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName("label_19");

        gridLayout_2->addWidget(label_19, 6, 0, 1, 1);

        checkBox_8 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_8->setObjectName("checkBox_8");

        gridLayout_2->addWidget(checkBox_8, 12, 0, 1, 1);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        checkBox_9 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_9->setObjectName("checkBox_9");

        gridLayout_2->addWidget(checkBox_9, 11, 0, 1, 1);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName("checkBox_3");

        gridLayout_2->addWidget(checkBox_3, 4, 0, 1, 1);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_7->setObjectName("checkBox_7");

        gridLayout_2->addWidget(checkBox_7, 10, 0, 1, 1);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName("checkBox_2");

        gridLayout_2->addWidget(checkBox_2, 2, 0, 1, 1);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName("label_18");

        gridLayout_2->addWidget(label_18, 13, 0, 1, 1);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName("checkBox_5");

        gridLayout_2->addWidget(checkBox_5, 7, 0, 1, 1);

        checkBox_6 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_6->setObjectName("checkBox_6");

        gridLayout_2->addWidget(checkBox_6, 1, 0, 1, 1);

        checkBox_11 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_11->setObjectName("checkBox_11");

        gridLayout_2->addWidget(checkBox_11, 14, 0, 1, 1);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName("checkBox_4");

        gridLayout_2->addWidget(checkBox_4, 5, 0, 1, 1);

        conditionsScrollArea->setWidget(scrollAreaWidgetContents);
        viewSettingsScrollArea = new QScrollArea(sideMenuGroupBox);
        viewSettingsScrollArea->setObjectName("viewSettingsScrollArea");
        viewSettingsScrollArea->setGeometry(QRect(0, 440, 321, 151));
        viewSettingsScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 349, 356));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_3->setObjectName("gridLayout_3");
        checkBox_circles = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_circles->setObjectName("checkBox_circles");

        gridLayout_3->addWidget(checkBox_circles, 14, 0, 1, 1);

        checkBox_indicies = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_indicies->setObjectName("checkBox_indicies");

        gridLayout_3->addWidget(checkBox_indicies, 15, 0, 1, 1);

        checkBox_leaf = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_leaf->setObjectName("checkBox_leaf");

        gridLayout_3->addWidget(checkBox_leaf, 10, 0, 1, 1);

        checkBox_branch = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_branch->setObjectName("checkBox_branch");

        gridLayout_3->addWidget(checkBox_branch, 11, 0, 1, 1);

        crease_view = new QRadioButton(scrollAreaWidgetContents_3);
        crease_view->setObjectName("crease_view");

        gridLayout_3->addWidget(crease_view, 1, 5, 1, 1);

        checkBox_nodes = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_nodes->setObjectName("checkBox_nodes");

        gridLayout_3->addWidget(checkBox_nodes, 9, 0, 1, 1);

        plan_view = new QRadioButton(scrollAreaWidgetContents_3);
        plan_view->setObjectName("plan_view");

        gridLayout_3->addWidget(plan_view, 1, 7, 1, 1);

        checkBox_labels = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_labels->setObjectName("checkBox_labels");

        gridLayout_3->addWidget(checkBox_labels, 18, 0, 1, 1);

        checkBox_sub = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_sub->setObjectName("checkBox_sub");

        gridLayout_3->addWidget(checkBox_sub, 12, 0, 1, 1);

        checkBox_coordinates = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_coordinates->setObjectName("checkBox_coordinates");

        gridLayout_3->addWidget(checkBox_coordinates, 16, 0, 1, 1);

        checkBox_dots = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_dots->setObjectName("checkBox_dots");

        gridLayout_3->addWidget(checkBox_dots, 13, 0, 1, 1);

        checkBox_elevation = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_elevation->setObjectName("checkBox_elevation");

        gridLayout_3->addWidget(checkBox_elevation, 17, 0, 1, 1);

        tree_view = new QRadioButton(scrollAreaWidgetContents_3);
        tree_view->setObjectName("tree_view");
        tree_view->setMaximumSize(QSize(71, 16777215));

        gridLayout_3->addWidget(tree_view, 1, 0, 1, 1);

        design_view = new QRadioButton(scrollAreaWidgetContents_3);
        design_view->setObjectName("design_view");

        gridLayout_3->addWidget(design_view, 1, 4, 1, 1);

        viewSettingsScrollArea->setWidget(scrollAreaWidgetContents_3);
        label_conditions = new QLabel(sideMenuGroupBox);
        label_conditions->setObjectName("label_conditions");
        label_conditions->setGeometry(QRect(10, 200, 151, 20));
        label_view_settings = new QLabel(sideMenuGroupBox);
        label_view_settings->setObjectName("label_view_settings");
        label_view_settings->setGeometry(QRect(10, 420, 121, 20));

        gridLayout_4->addWidget(sideMenuGroupBox, 0, 1, 1, 1, Qt::AlignRight);

        drawingAreaGroupBox = new QGroupBox(centralwidget);
        drawingAreaGroupBox->setObjectName("drawingAreaGroupBox");
        sizePolicy.setHeightForWidth(drawingAreaGroupBox->sizePolicy().hasHeightForWidth());
        drawingAreaGroupBox->setSizePolicy(sizePolicy);
        drawingAreaGroupBox->setMinimumSize(QSize(645, 0));
        canvas = = new class CanvasWidget(drawingAreaGroupBox);
        canvas->setObjectName("canvas");
        canvas->setGeometry(QRect(0, 0, 641, 571));
        sizePolicy.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(drawingAreaGroupBox, 0, 0, 1, 1);

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
        sideMenuGroupBox->setTitle(QString());
        label_inspector->setText(QCoreApplication::translate("MainWindow", "Inspector", nullptr));
#if QT_CONFIG(accessibility)
        inspectorScrollArea->setAccessibleName(QCoreApplication::translate("MainWindow", "inspector box", nullptr));
#endif // QT_CONFIG(accessibility)
        input_width->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        input_Y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_symmetry->setText(QCoreApplication::translate("MainWindow", "Symmetry", nullptr));
        label_scale->setText(QCoreApplication::translate("MainWindow", "Scale =", nullptr));
        label_width->setText(QCoreApplication::translate("MainWindow", "Width =", nullptr));
        input_X->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        input_scale->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_X->setText(QCoreApplication::translate("MainWindow", "X =", nullptr));
        label_Y->setText(QCoreApplication::translate("MainWindow", "Y =", nullptr));
        label_height->setText(QCoreApplication::translate("MainWindow", "Height =", nullptr));
        input_height->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_angle->setText(QCoreApplication::translate("MainWindow", "Angle =", nullptr));
        input_angle->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toggle_linear->setText(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        toggle_diagonal->setText(QCoreApplication::translate("MainWindow", "Diagonal", nullptr));
        checkBox_10->setText(QCoreApplication::translate("MainWindow", "Angle Fixed", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "3 Nodes Colinear", nullptr));
        label_19->setText(QString());
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "2 Edges Same Strain", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Node(s) fixed to...", nullptr));
        checkBox_9->setText(QCoreApplication::translate("MainWindow", "Edge(s) No Strain", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Corner", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "Remove All Node Conditions", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Paper Edge", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Path...", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "2 Nodes Paired About Symmetry Line", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "Symmetry Line", nullptr));
        checkBox_11->setText(QCoreApplication::translate("MainWindow", "Active", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        checkBox_circles->setText(QCoreApplication::translate("MainWindow", "Circles", nullptr));
        checkBox_indicies->setText(QCoreApplication::translate("MainWindow", "Indices", nullptr));
        checkBox_leaf->setText(QCoreApplication::translate("MainWindow", "Leaf", nullptr));
        checkBox_branch->setText(QCoreApplication::translate("MainWindow", "Branch", nullptr));
        crease_view->setText(QCoreApplication::translate("MainWindow", "Crease", nullptr));
        checkBox_nodes->setText(QCoreApplication::translate("MainWindow", "Nodes", nullptr));
        plan_view->setText(QCoreApplication::translate("MainWindow", "Plan", nullptr));
        checkBox_labels->setText(QCoreApplication::translate("MainWindow", "Labels", nullptr));
        checkBox_sub->setText(QCoreApplication::translate("MainWindow", "Sub", nullptr));
        checkBox_coordinates->setText(QCoreApplication::translate("MainWindow", "Coordinates", nullptr));
        checkBox_dots->setText(QCoreApplication::translate("MainWindow", "Dots", nullptr));
        checkBox_elevation->setText(QCoreApplication::translate("MainWindow", "Elevation", nullptr));
        tree_view->setText(QCoreApplication::translate("MainWindow", "Tree", nullptr));
        design_view->setText(QCoreApplication::translate("MainWindow", "Design", nullptr));
        label_conditions->setText(QCoreApplication::translate("MainWindow", "Conditions", nullptr));
        label_view_settings->setText(QCoreApplication::translate("MainWindow", "View Settings", nullptr));
        drawingAreaGroupBox->setTitle(QString());
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

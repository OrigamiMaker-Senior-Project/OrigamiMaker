QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvaswidget.cpp \
    main.cpp \
    mainwindow.cpp \
    tmDoc.cpp \
    tmHeader.cpp \
    tmModel/tmCluster.cpp \
    tmModel/tmEdge.cpp \
    tmModel/tmNode.cpp \
    tmModel/tmPart.cpp \
    tmModel/tmTree.cpp

HEADERS += \
    canvaswidget.h \
    mainwindow.h \
    tmDoc.h \
    tmHeader.h \
    tmModel/tmArray.h \
    tmModel/tmArrayIterator.h \
    tmModel/tmCluster.h \
    tmModel/tmDpptr.h \
    tmModel/tmDpptrArray.h \
    tmModel/tmDpptrSrc.h \
    tmModel/tmEdge.h \
    tmModel/tmModel.h \
    tmModel/tmModel_fwd.h \
    tmModel/tmNode.h \
    tmModel/tmPart.h \
    tmModel/tmPoint.h \
    tmModel/tmTree.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

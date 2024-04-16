QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    CanvasWidget.cpp \
    Parser.cpp \
    TreeModelWrapper.cpp \
    main.cpp \
    mainwindow.cpp \
    tmModel/tmTree.cpp \
    tmModel/tmNode.cpp \
    tmModel/tmEdge.cpp \
    tmModel/tmCluster.cpp \
    tmModel/tmTreeCleaner.cpp \
    tmModel/tmPoly.cpp \
    tmModel/tmPath.cpp \
    tmModel/tmVertex.cpp \
    tmModel/tmCrease.cpp \
    tmModel/tmFacet.cpp \
    tmModel/tmCondition.cpp \
    tmModel/tmConditionEdgeLengthFixed.cpp \
    tmModel/tmConditionEdgesSameStrain.cpp \
    tmModel/tmConditionNodeCombo.cpp \
    tmModel/tmConditionNodeFixed.cpp \
    tmModel/tmConditionNodeOnCorner.cpp \
    tmModel/tmConditionNodeOnEdge.cpp \
    tmModel/tmConditionNodesCollinear.cpp \
    tmModel/tmConditionNodesPaired.cpp \
    tmModel/tmConditionNodeSymmetric.cpp \
    tmModel/tmConditionOwner.cpp \
    tmModel/tmConditionPathActive.cpp \
    tmModel/tmConditionPathAngleFixed.cpp \
    tmModel/tmConditionPathAngleQuant.cpp \
    tmModel/tmConditionPathCombo.cpp \
    tmModel/tmCreaseOwner.cpp \
    tmModel/tmEdgeOwner.cpp \
    tmModel/tmFacetOwner.cpp \
    tmModel/tmNodeOwner.cpp \
    tmModel/tmPathOwner.cpp \
    tmModel/tmPolyOwner.cpp \
    tmModel/tmVertexOwner.cpp \
    tmModel/tmDpptrTarget.cpp \
    tmModel/tmDpptrArray.cpp \
    tmModel/tmConstraintFns.cpp \
    tmModel/tmEdgeOptimizer.cpp \
    tmModel/tmOptimizer.cpp \
    tmModel/tmScaleOptimizer.cpp \
    tmModel/tmStrainOptimizer.cpp \
    tmModel/tmStubFinder.cpp \
    tmModel/tmTree_FacetOrder.cpp \
    tmModel/tmTree_IO.cpp \
    tmModel/tmTree_TestTrees.cpp \
    tmModel/tmPoint.cpp \
    tmModel/tmPart.cpp \
    tmModel/tmHeader.cpp

HEADERS += \
    CanvasWidget.h \
    Parser.h \
    TreeModelWrapper.h \
    mainwindow.h \
    tmModel/tmArray.h \
    tmModel/tmArrayIterator.h \
    tmModel/tmCluster.h \
    tmModel/tmCondition.h \
    tmModel/tmConditionEdgeLengthFixed.h \
    tmModel/tmConditionEdgesSameStrain.h \
    tmModel/tmConditionNodeCombo.h \
    tmModel/tmConditionNodeFixed.h \
    tmModel/tmConditionNodeOnCorner.h \
    tmModel/tmConditionNodeOnEdge.h \
    tmModel/tmConditionNodesCollinear.h \
    tmModel/tmConditionNodesPaired.h \
    tmModel/tmConditionNodeSymmetric.h \
    tmModel/tmConditionOwner.h \
    tmModel/tmConditionPathActive.h \
    tmModel/tmConditionPathAngleFixed.h \
    tmModel/tmConditionPathAngleQuant.h \
    tmModel/tmConditionPathCombo.h \
    tmModel/tmCreaseOwner.h \
    tmModel/tmEdgeOwner.h \
    tmModel/tmFacetOwner.h \
    tmModel/tmNodeOwner.h \
    tmModel/tmPathOwner.h \
    tmModel/tmPolyOwner.h \
    tmModel/tmVertexOwner.h \
    tmModel/tmDpptrTarget.h \
    tmModel/tmDpptrArray.h \
    tmModel/tmConstraintFns.h \
    tmModel/tmEdgeOptimizer.h \
    tmModel/tmOptimizer.h \
    tmModel/tmScaleOptimizer.h \
    tmModel/tmStrainOptimizer.h \
    tmModel/tmStubFinder.h \
    tmModel/tmTree_FacetOrder.h \
    tmModel/tmTree_IO.h \
    tmModel/tmTree_TestTrees.h \
    tmModel/tmPoint.h \
    tmModel/tmPart.h \
    tmModel/tmHeader.h \
    tmModel/tmTree.h \
    tmModel/tmNode.h \
    tmModel/tmEdge.h \
    tmModel/tmCluster.h \
    tmModel/tmTreeCleaner.h \
    tmModel/tmPoly.h \
    tmModel/tmPath.h \
    tmModel/tmVertex.h \
    tmModel/tmCrease.h \
    tmModel/tmFacet.h \
    tmModel/tmCondition.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    stylesheet.css

RESOURCES += \
    resources.qrc

INCLUDEPATH += $$PWD/tmModel
DEPENDPATH += $$PWD/tmModel

# Run the Makefile
# system(make -f $$PWD/Makefile)

# Link against the generated library
#LIBS += -L$$PWD -ltmModel

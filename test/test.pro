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
    tmModel/tmTree.cpp \
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
    tmModel/tmCrease.cpp \
    tmModel/tmCreaseOwner.cpp \
    tmModel/tmDpptrArray.cpp \
    tmModel/tmDpptrTarget.cpp \
    tmModel/tmEdgeOwner.cpp \
    tmModel/tmFacet.cpp \
    tmModel/tmFacetOwner.cpp \
    tmModel/tmNodeOwner.cpp \
    tmModel/tmPath.cpp \
    tmModel/tmPathOwner.cpp \
    tmModel/tmPoint.cpp \
    tmModel/tmPoly.cpp \
    tmModel/tmPolyOwner.cpp \
    tmModel/tmVertex.cpp \
    tmModel/tmVertexOwner.cpp \
    tmModel/tmConstraintFns.cpp \
    tmModel/tmEdgeOptimizer.cpp \
    tmModel/tmOptimizer.cpp \
    tmModel/tmScaleOptimizer.cpp \
    tmModel/tmStrainOptimizer.cpp \
    tmModel/tmStubFinder.cpp \
    tmModel/tmTree_FacetOrder.cpp \
    tmModel/tmTree_IO.cpp \
    tmModel/tmTree_TestTrees.cpp

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
    tmModel/tmTree.h \
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
    tmModel/tmCrease.h \
    tmModel/tmCreaseOwner.h \
    tmModel/tmDpptrTarget.h \
    tmModel/tmEdgeOwner.h \
    tmModel/tmFacet.h \
    tmModel/tmFacetOwner.h \
    tmModel/tmNodeOwner.h \
    tmModel/tmPath.h \
    tmModel/tmPathOwner.h \
    tmModel/tmPoly.h \
    tmModel/tmPolyOwner.h \
    tmModel/tmVertex.h \
    tmModel/tmVertexOwner.h \
    tmModel/tmConstraintFns.h \
    tmModel/tmEdgeOptimizer.h \
    tmModel/tmOptimizer.h \
    tmModel/tmScaleOptimizer.h \
    tmModel/tmStrainOptimizer.h \
    tmModel/tmStubFinder.h \
    tmModel/tmMatrix.h \
    tmModel/tmNewtonRaphson.h \
    tmModel/tmPtrClasses.h \
    tmModel/tmSolvers \
    tmModel/tmTreeClasses.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

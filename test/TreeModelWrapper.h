#ifndef TREEMODELWRAPPER_H
#define TREEMODELWRAPPER_H

#include "tmModel/tmTree.h"
#include <QObject>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <cstring>

struct NodeData {
    int id;
    double x;
    double y;
    std::string label;
};

struct EdgeData {
    int id;
    int node1Id;
    int node2Id;
    std::string label;
};

class TreeModelWrapper : public QObject {
    Q_OBJECT
public:
    TreeModelWrapper();
    ~TreeModelWrapper();

    tmNode* createNode(double x, double y, tmNode* parentNode = nullptr);
    void createNodesFromList(const std::vector<std::pair<double, double>>& nodePositions);
    tmTree* createTreeFromList(const std::vector<std::pair<double, double>>& nodePositions);

    int getNodeCount() const;
    int getEdgeCount() const;
    std::vector<NodeData> getNodeData() const;
    std::vector<EdgeData> getEdgeData() const;

    void buildTreePolys();
    void buildPolysAndCreasePattern();
    bool hasFullCreasePattern() const;
    tmTree::CPStatus getCreasePatternStatus(tmArray<tmEdge*>& badEdges, tmArray<tmPoly*>& badPolys,
                                            tmArray<tmVertex*>& badVertices, tmArray<tmCrease*>& badCreases,
                                            tmArray<tmFacet*>& badFacets);
    void getLeafNodes(tmArray<tmNode*>& aNodeList);
    void getBorderNodes(tmArray<tmNode*>& aNodeList);
    void getLeafPaths(tmArray<tmPath*>& aPathList);
    void getSpanningEdges(const tmArray<tmNode*>& aNodeList, tmArray<tmEdge*>& aEdgeList);
    void getSpanningPaths(const tmArray<tmNode*>& aNodeList, tmArray<tmPath*>& aPathList);
    void filterLeafNodes(tmDpptrArray<tmNode>& aNodeList);
    void filterMovableParts(tmDpptrArray<tmNode>& aNodeList, tmDpptrArray<tmEdge>& aEdgeList);
    void setNodesFixedToSymmetryLine(const tmArray<tmNode*>& nodes);
    void setNodesFixedToPaperEdge(const tmArray<tmNode*>& nodes);
    void setNodesFixedToPaperCorner(const tmArray<tmNode*>& nodes);
    void setNodesFixedToPosition(const tmArray<tmNode*>& nodes, bool xFixed, tmFloat xFixValue,
                                 bool yFixed, tmFloat yFixValue);
    void setEdgesSameStrain(const tmArray<tmEdge*>& edges);
    void setPathsActive(const tmArray<tmPath*>& paths);
    void setPathsAngleFixed(const tmArray<tmPath*>& paths, tmFloat angle);
    void setPathsAngleQuant(const tmArray<tmPath*>& paths, size_t quant, tmFloat quantOffset);

    bool isTreeOptimized() const;
    void buildCreasePattern();
    void optimizeTree();
    void scaleOptimization();
    void strainOptimization();
    void edgeOptimization(tmDpptrArray<tmNode>& nodes, tmDpptrArray<tmEdge>& edges);
    void setTreeScale();
    std::vector<std::pair<QPointF, QPointF>> getCreasePattern() const;


    void connectSignals(QObject *receiver);


    void testCreateTreeFromList(TreeModelWrapper& wrapper, const std::vector<std::pair<double, double>>& nodePositions);
    void testGetNodeAndEdgeData(TreeModelWrapper& wrapper);
    void testCreasePattern(TreeModelWrapper& wrapper);
    void runTests();



signals:
    void treeUpdated();

private:
    tmTree* tree;
    std::unordered_map<int, tmNode*> nodeMap;
    std::unordered_map<int, tmEdge*> edgeMap;
    int nextNodeId;
    int nextEdgeId;

    void cleanupAfterEdit();

    void removeStrain(tmArray<tmEdge*>& aEdgeList);
    void removeAllStrain();
    void perturbNodes(const tmArray<tmNode*>& aNodeList);
    bool canPerturbAllNodes() const;
    void perturbAllNodes();

};

#endif // TREEMODELWRAPPER_H

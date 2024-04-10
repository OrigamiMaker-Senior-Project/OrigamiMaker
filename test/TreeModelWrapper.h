#ifndef TREEMODELWRAPPER_H
#define TREEMODELWRAPPER_H

#include "tmModel/tmTree.h"
#include "tmModel/tmTreeClasses.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

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

class TreeModelWrapper {
public:
    TreeModelWrapper();
    ~TreeModelWrapper();

    int createNode(double x, double y, int parentNodeId = -1);
    int splitEdge(int edgeId, double splitRatio);
    void setNodeLabel(int nodeId, const std::string& label);
    void setEdgeLabel(int edgeId, const std::string& label);
    int getNodeCount() const;
    int getEdgeCount() const;
    std::pair<double, double> getNodePosition(int nodeId) const;
    std::vector<NodeData> getNodeData() const;
    std::vector<EdgeData> getEdgeData() const;

    void buildTreePolys();
    void buildPolysAndCreasePattern();
    bool hasFullCP() const;
    tmTree::CPStatus getCPStatus(tmArray<tmEdge*>& badEdges, tmArray<tmPoly*>& badPolys,
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

    tmTree* makeTreeBlank();
    tmTree* makeTreeUnoptimized();
    tmTree* makeTreeOptimized();
    tmTree* makeTreeGusset();
    tmTree* makeTreeConditioned();
    
private:
    tmTree* tree;
    std::unordered_map<int, tmNode*> nodeMap;
    std::unordered_map<int, tmEdge*> edgeMap;
    int nextNodeId;
    int nextEdgeId;

    void cleanupAfterEdit();
};

#endif // TREEMODELWRAPPER_H
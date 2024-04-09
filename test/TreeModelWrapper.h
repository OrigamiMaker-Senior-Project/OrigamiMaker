#ifndef TREEMODELWRAPPER_H
#define TREEMODELWRAPPER_H

#include "tmModel/tmTree.h"
#include "tmModel/tmTreeClasses.h"
#include <string>
#include <vector>
#include <unordered_map>

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

    int createNode(double x, double y);
    int createEdge(int nodeId1, int nodeId2);
    void setNodeLabel(int nodeId, const std::string& label);
    void setEdgeLabel(int edgeId, const std::string& label);
    int getNodeCount() const;
    int getEdgeCount() const;
    std::pair<double, double> getNodePosition(int nodeId) const;
    std::vector<NodeData> getNodeData() const;
    std::vector<EdgeData> getEdgeData() const;

private:
    tmTree* tree;
    std::unordered_map<int, tmNode*> nodeMap;
    std::unordered_map<int, tmEdge*> edgeMap;
    int nextNodeId;
    int nextEdgeId;
};

#endif // TREEMODELWRAPPER_H
#include "TreeModelWrapper.h"

TreeModelWrapper::TreeModelWrapper() {
    tree = new tmTree();
    nextNodeId = 1;
    nextEdgeId = 1;
}

TreeModelWrapper::~TreeModelWrapper() {
    delete tree;
}

int TreeModelWrapper::createNode(double x, double y) {
    tmNode* newNode;
    tmEdge* newEdge;
    tree->AddNode(nullptr, tmPoint(x, y), newNode, newEdge);
    int nodeId = nextNodeId++;
    nodeMap[nodeId] = newNode;
    return nodeId;
}

int TreeModelWrapper::createEdge(int nodeId1, int nodeId2) {
    auto it1 = nodeMap.find(nodeId1);
    auto it2 = nodeMap.find(nodeId2);
    if (it1 == nodeMap.end() || it2 == nodeMap.end()) {
        return -1; // Invalid node IDs
    }
    tmNode* node1 = it1->second;
    tmNode* node2 = it2->second;
    tmEdge* newEdge;
    tree->AddNode(node1, node2->GetLoc(), node2, newEdge);
    int edgeId = nextEdgeId++;
    edgeMap[edgeId] = newEdge;
    return edgeId;
}

void TreeModelWrapper::setNodeLabel(int nodeId, const std::string& label) {
    auto it = nodeMap.find(nodeId);
    if (it != nodeMap.end()) {
        tmNode* node = it->second;
        node->SetLabel(label.c_str());
    }
}

void TreeModelWrapper::setEdgeLabel(int edgeId, const std::string& label) {
    auto it = edgeMap.find(edgeId);
    if (it != edgeMap.end()) {
        tmEdge* edge = it->second;
        edge->SetLabel(label.c_str());
    }
}

int TreeModelWrapper::getNodeCount() const {
    return tree->GetNumNodes();
}

int TreeModelWrapper::getEdgeCount() const {
    return tree->GetNumEdges();
}

std::pair<double, double> TreeModelWrapper::getNodePosition(int nodeId) const {
    auto it = nodeMap.find(nodeId);
    if (it != nodeMap.end()) {
        tmNode* node = it->second;
        return std::make_pair(node->GetLoc().x, node->GetLoc().y);
    }
    return std::make_pair(0.0, 0.0);
}

std::vector<NodeData> TreeModelWrapper::getNodeData() const {
    std::vector<NodeData> nodeData;
    for (const auto& pair : nodeMap) {
        int nodeId = pair.first;
        tmNode* node = pair.second;
        NodeData data;
        data.id = nodeId;
        data.x = node->GetLoc().x;
        data.y = node->GetLoc().y;
        data.label = node->GetLabel();
        nodeData.push_back(data);
    }
    return nodeData;
}

std::vector<EdgeData> TreeModelWrapper::getEdgeData() const {
    std::vector<EdgeData> edgeData;
    for (const auto& pair : edgeMap) {
        int edgeId = pair.first;
        tmEdge* edge = pair.second;
        EdgeData data;
        data.id = edgeId;
        
        // Get the node IDs instead of the tmNode* pointers
        int node1Id = edge->GetNodes().front()->GetIndex();
        int node2Id = edge->GetNodes().back()->GetIndex();
        
        // Use the node IDs to retrieve the corresponding tmNode* pointers from nodeMap
        data.node1Id = nodeMap.at(node1Id)->GetIndex();
        data.node2Id = nodeMap.at(node2Id)->GetIndex();
        
        data.label = edge->GetLabel();
        edgeData.push_back(data);
    }
    return edgeData;
}
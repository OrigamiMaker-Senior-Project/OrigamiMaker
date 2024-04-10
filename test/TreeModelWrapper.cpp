#include "TreeModelWrapper.h"
#include <iostream>

TreeModelWrapper::TreeModelWrapper() {
    tree = new tmTree();
    nextNodeId = 1;
    nextEdgeId = 1;
}

TreeModelWrapper::~TreeModelWrapper() {
    delete tree;
}

int TreeModelWrapper::createNode(double x, double y, int parentNodeId) {
    tmNode* parentNode = nullptr;
    if (parentNodeId != -1) {
        auto it = nodeMap.find(parentNodeId);
        if (it == nodeMap.end()) {
            std::cerr << "Invalid parent node ID: " << parentNodeId << std::endl;
            return -1;
        }
        parentNode = it->second;
    }

    tmNode* newNode;
    tmEdge* newEdge;
    try {
        tree->AddNode(parentNode, tmPoint(x, y), newNode, newEdge);
    } catch (const std::exception& e) {
        std::cerr << "Error creating node: " << e.what() << std::endl;
        return -1;
    }

    int nodeId = nextNodeId++;
    nodeMap[nodeId] = newNode;
    if (newEdge != nullptr) {
        int edgeId = nextEdgeId++;
        edgeMap[edgeId] = newEdge;
        std::cout << "Created edge with ID: " << edgeId << std::endl;
    }

    std::cout << "Created node with ID: " << nodeId << std::endl;
    std::cout << "Node location: (" << x << ", " << y << ")" << std::endl;
    cleanupAfterEdit();
    return nodeId;
}



int TreeModelWrapper::splitEdge(int edgeId, double splitRatio) {
    auto it = edgeMap.find(edgeId);
    if (it == edgeMap.end()) {
        std::cerr << "Invalid edge ID: " << edgeId << std::endl;
        return -1;
    }
    tmEdge* edge = it->second;

    tmNode* newNode;
    try {
        tree->SplitEdge(edge, splitRatio, newNode);
    } catch (const std::exception& e) {
        std::cerr << "Error splitting edge: " << e.what() << std::endl;
        return -1;
    }

    int nodeId = nextNodeId++;
    nodeMap[nodeId] = newNode;
    std::cout << "Created node with ID: " << nodeId << std::endl;
    std::cout << "Node location: (" << newNode->GetLoc().x << ", " << newNode->GetLoc().y << ")" << std::endl;
    cleanupAfterEdit();
    return nodeId;
}

void TreeModelWrapper::setNodeLabel(int nodeId, const std::string& label) {
    auto it = nodeMap.find(nodeId);
    if (it != nodeMap.end()) {
        tmNode* node = it->second;
        node->SetLabel(label.c_str());
        std::cout << "Set label for node " << nodeId << ": " << label << std::endl;
    } else {
        std::cerr << "Invalid node ID for setting label: " << nodeId << std::endl;
    }
}

void TreeModelWrapper::setEdgeLabel(int edgeId, const std::string& label) {
    auto it = edgeMap.find(edgeId);
    if (it != edgeMap.end()) {
        tmEdge* edge = it->second;
        edge->SetLabel(label.c_str());
        std::cout << "Set label for edge " << edgeId << ": " << label << std::endl;
    } else {
        std::cerr << "Invalid edge ID for setting label: " << edgeId << std::endl;
    }
}

int TreeModelWrapper::getNodeCount() const {
    int count = tree->GetNumNodes();
    std::cout << "Node count: " << count << std::endl;
    return count;
}

int TreeModelWrapper::getEdgeCount() const {
    int count = tree->GetNumEdges();
    std::cout << "Edge count: " << count << std::endl;
    return count;
}

std::pair<double, double> TreeModelWrapper::getNodePosition(int nodeId) const {
    auto it = nodeMap.find(nodeId);
    if (it != nodeMap.end()) {
        tmNode* node = it->second;
        double x = node->GetLoc().x;
        double y = node->GetLoc().y;
        std::cout << "Node " << nodeId << " position: (" << x << ", " << y << ")" << std::endl;
        return std::make_pair(x, y);
    }
    std::cerr << "Invalid node ID for getting position: " << nodeId << std::endl;
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
    std::cout << "Retrieved data for " << nodeData.size() << " nodes" << std::endl;
    return nodeData;
}

std::vector<EdgeData> TreeModelWrapper::getEdgeData() const {
    std::vector<EdgeData> edgeData;
    for (const auto& pair : edgeMap) {
        int edgeId = pair.first;
        tmEdge* edge = pair.second;
        EdgeData data;
        data.id = edgeId;
        
        // Get the node IDs from the nodeMap
        auto it1 = std::find_if(nodeMap.begin(), nodeMap.end(), 
            [&](const std::pair<int, tmNode*>& p) { return p.second == edge->GetNodes().front(); });
        auto it2 = std::find_if(nodeMap.begin(), nodeMap.end(), 
            [&](const std::pair<int, tmNode*>& p) { return p.second == edge->GetNodes().back(); });
        
        if (it1 != nodeMap.end() && it2 != nodeMap.end()) {
            data.node1Id = it1->first;
            data.node2Id = it2->first;
        } else {
            std::cerr << "Error getting node IDs for edge " << edgeId << std::endl;
        }
        
        data.label = edge->GetLabel();
        edgeData.push_back(data);
    }
    std::cout << "Retrieved data for " << edgeData.size() << " edges" << std::endl;
    return edgeData;
}

tmTree* TreeModelWrapper::makeTreeBlank() {
    delete tree;
    tree = tmTree::MakeTreeBlank();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    std::cout << "Created blank tree" << std::endl;
    return tree;
}

void TreeModelWrapper::cleanupAfterEdit() {
    tree->CleanupAfterEdit();
}

// more stuff
tmTree* TreeModelWrapper::makeTreeUnoptimized() {
    cleanupAfterEdit();
    delete tree;
    tree = tmTree::MakeTreeUnoptimized();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i) {
        tmNode* node = tree->GetNodes()[i];
        nodeMap[nextNodeId++] = node;
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i) {
        tmEdge* edge = tree->GetEdges()[i];
        edgeMap[nextEdgeId++] = edge;
    }
    std::cout << "Created unoptimized tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}

tmTree* TreeModelWrapper::makeTreeOptimized() {
    cleanupAfterEdit();
    delete tree;
    tree = tmTree::MakeTreeOptimized();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i) {
        tmNode* node = tree->GetNodes()[i];
        nodeMap[nextNodeId++] = node;
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i) {
        tmEdge* edge = tree->GetEdges()[i];
        edgeMap[nextEdgeId++] = edge;
    }
    std::cout << "Created optimized tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}

tmTree* TreeModelWrapper::makeTreeGusset() {
    cleanupAfterEdit();
    delete tree;
    tree = tmTree::MakeTreeGusset();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i) {
        tmNode* node = tree->GetNodes()[i];
        nodeMap[nextNodeId++] = node;
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i) {
        tmEdge* edge = tree->GetEdges()[i];
        edgeMap[nextEdgeId++] = edge;
    }
    std::cout << "Created gusset tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}

tmTree* TreeModelWrapper::makeTreeConditioned() {
    cleanupAfterEdit();
    delete tree;
    tree = tmTree::MakeTreeConditioned();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i) {
        tmNode* node = tree->GetNodes()[i];
        nodeMap[nextNodeId++] = node;
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i) {
        tmEdge* edge = tree->GetEdges()[i];
        edgeMap[nextEdgeId++] = edge;
    }
    std::cout << "Created conditioned tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}



// crease pattern things

void TreeModelWrapper::buildTreePolys() {
    tree->BuildTreePolys();
}

void TreeModelWrapper::buildPolysAndCreasePattern() {
    tree->BuildPolysAndCreasePattern();
}

// Checks if the crease pattern is full
bool TreeModelWrapper::hasFullCP() const {
    return tree->HasFullCP();
}

// Crease pattern status
tmTree::CPStatus TreeModelWrapper::getCPStatus(tmArray<tmEdge*>& badEdges, tmArray<tmPoly*>& badPolys,
                                               tmArray<tmVertex*>& badVertices, tmArray<tmCrease*>& badCreases,
                                               tmArray<tmFacet*>& badFacets) {
    return tree->GetCPStatus(badEdges, badPolys, badVertices, badCreases, badFacets);
}

void TreeModelWrapper::getLeafNodes(tmArray<tmNode*>& aNodeList) {
    tree->GetLeafNodes(aNodeList);
}

void TreeModelWrapper::getBorderNodes(tmArray<tmNode*>& aNodeList) {
    tree->GetBorderNodes(aNodeList);
}

void TreeModelWrapper::getLeafPaths(tmArray<tmPath*>& aPathList) {
    tree->GetLeafPaths(aPathList);
}

void TreeModelWrapper::getSpanningEdges(const tmArray<tmNode*>& aNodeList, tmArray<tmEdge*>& aEdgeList) {
    tree->GetSpanningEdges(aNodeList, aEdgeList);
}

void TreeModelWrapper::getSpanningPaths(const tmArray<tmNode*>& aNodeList, tmArray<tmPath*>& aPathList) {
    tree->GetSpanningPaths(aNodeList, aPathList);
}

void TreeModelWrapper::filterLeafNodes(tmDpptrArray<tmNode>& aNodeList) {
    tree->FilterLeafNodes(aNodeList);
}

void TreeModelWrapper::filterMovableParts(tmDpptrArray<tmNode>& aNodeList, tmDpptrArray<tmEdge>& aEdgeList) {
    tree->FilterMovableParts(aNodeList, aEdgeList);
}

void TreeModelWrapper::setNodesFixedToSymmetryLine(const tmArray<tmNode*>& nodes) {
    tree->SetNodesFixedToSymmetryLine(nodes);
}

void TreeModelWrapper::setNodesFixedToPaperEdge(const tmArray<tmNode*>& nodes) {
    tree->SetNodesFixedToPaperEdge(nodes);
}

void TreeModelWrapper::setNodesFixedToPaperCorner(const tmArray<tmNode*>& nodes) {
    tree->SetNodesFixedToPaperCorner(nodes);
}

void TreeModelWrapper::setNodesFixedToPosition(const tmArray<tmNode*>& nodes, bool xFixed, tmFloat xFixValue,
                                               bool yFixed, tmFloat yFixValue) {
    tree->SetNodesFixedToPosition(nodes, xFixed, xFixValue, yFixed, yFixValue);
}

void TreeModelWrapper::setEdgesSameStrain(const tmArray<tmEdge*>& edges) {
    tree->SetEdgesSameStrain(edges);
}

void TreeModelWrapper::setPathsActive(const tmArray<tmPath*>& paths) {
    tree->SetPathsActive(paths);
}

void TreeModelWrapper::setPathsAngleFixed(const tmArray<tmPath*>& paths, tmFloat angle) {
    tree->SetPathsAngleFixed(paths, angle);
}

void TreeModelWrapper::setPathsAngleQuant(const tmArray<tmPath*>& paths, size_t quant, tmFloat quantOffset) {
    tree->SetPathsAngleQuant(paths, quant, quantOffset);
}
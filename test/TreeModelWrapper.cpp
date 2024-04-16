#include "TreeModelWrapper.h"
#include <iostream>

TreeModelWrapper::TreeModelWrapper()
{
    tree = new tmTree();
    nextNodeId = 1;
    nextEdgeId = 1;
}

TreeModelWrapper::~TreeModelWrapper()
{
    delete tree;
}

int TreeModelWrapper::createNode(double x, double y, int parentNodeId)
{
    tmNode *parentNode = nullptr;
    if (parentNodeId != -1)
    {
        auto it = nodeMap.find(parentNodeId);
        if (it == nodeMap.end())
        {
            std::cerr << "Invalid parent node ID: " << parentNodeId << std::endl;
            return -1;
        }
        parentNode = it->second;
    }

    tmNode *newNode;
    tmEdge *newEdge;
    try
    {
        tree->AddNode(parentNode, tmPoint(x, y), newNode, newEdge);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error creating node: " << e.what() << std::endl;
        return -1;
    }

    int nodeId = nextNodeId++;
    nodeMap[nodeId] = newNode;
    if (newEdge != nullptr)
    {
        int edgeId = nextEdgeId++;
        edgeMap[edgeId] = newEdge;
        std::cout << "Created edge label: " << std::to_string(edgeId).c_str() << std::endl;
        newEdge->SetLabel(std::to_string(edgeId).c_str()); // Set the edge label
        std::cout << "Created edge with ID: " << edgeId << ", Label: " << newEdge->GetLabel() << std::endl;
    }
    std::cout << "Setting node Label...." << nodeId << std::endl;
    newNode->SetLabel(std::to_string(nodeId).c_str());
    std::cout << "Created node with ID: " << nodeId << ", Label: " << newNode->GetLabel() << std::endl;
    std::cout << "Node location: (" << x << ", " << y << ")" << std::endl;
    cleanupAfterEdit();
    return nodeId;
}

int TreeModelWrapper::splitEdge(int edgeId, double splitRatio)
{
    std::cout << "Splitting edge " << edgeId << " at ratio " << splitRatio << std::endl;
    auto it = edgeMap.find(edgeId);
    if (it == edgeMap.end())
    {
        std::cerr << "Invalid edge ID: " << edgeId << std::endl;
        return -1;
    }
    tmEdge *edge = it->second;

    tmNode *newNode;
    try
    {
        tree->SplitEdge(edge, splitRatio, newNode);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error splitting edge: " << e.what() << std::endl;
        return -1;
    }

    int nodeId = nextNodeId++;
    nodeMap[nodeId] = newNode;
    std::cout << "Created node with ID: " << nodeId << std::endl;
    std::cout << "Node location: (" << newNode->GetLoc().x << ", " << newNode->GetLoc().y << ")" << std::endl;
    newNode->SetLabel(std::to_string(nodeId).c_str());
    // Update the edge map
    edgeMap.erase(edgeId);
    for (size_t i = 0; i < newNode->GetEdges().size(); ++i)
    {
        tmEdge *newEdge = newNode->GetEdges()[i];
        int newEdgeId = nextEdgeId++;
        edgeMap[newEdgeId] = newEdge;
        newEdge->SetLabel(std::to_string(newEdgeId).c_str());
        std::cout << "Created edge with ID: " << newEdgeId << std::endl;
    }

    cleanupAfterEdit();
    return nodeId;
}

void TreeModelWrapper::setNodeLabel(int nodeId, const std::string &label)
{
    auto it = nodeMap.find(nodeId);
    if (it != nodeMap.end())
    {
        tmNode *node = it->second;
        node->SetLabel(label.c_str());
        std::cout << "Set label for node " << nodeId << ": " << label << std::endl;
    }
    else
    {
        std::cerr << "Invalid node ID for setting label: " << nodeId << std::endl;
    }
}

void TreeModelWrapper::setEdgeLabel(int edgeId, const std::string &label)
{
    std::cout << "Setting label for edge " << edgeId << ": " << label << std::endl;
    auto it = edgeMap.find(edgeId);
    if (it != edgeMap.end())
    {
        tmEdge *edge = it->second;
        edge->SetLabel(label.c_str());
        std::cout << "Set label for edge " << edgeId << ": " << label << std::endl;
    }
    else
    {
        std::cerr << "Invalid edge ID for setting label: " << edgeId << std::endl;
    }
}

int TreeModelWrapper::getNodeCount() const
{
    int count = tree->GetNumNodes();
    std::cout << "Node count: " << count << std::endl;
    return count;
}

int TreeModelWrapper::getEdgeCount() const
{
    int count = tree->GetNumEdges();
    std::cout << "Edge count: " << count << std::endl;
    return count;
}

std::pair<double, double> TreeModelWrapper::getNodePosition(int nodeId) const
{
    auto it = nodeMap.find(nodeId);
    if (it != nodeMap.end())
    {
        tmNode *node = it->second;
        double x = node->GetLoc().x;
        double y = node->GetLoc().y;
        std::cout << "Node " << nodeId << " position: (" << x << ", " << y << ")" << std::endl;
        return std::make_pair(x, y);
    }
    std::cerr << "Invalid node ID for getting position: " << nodeId << std::endl;
    return std::make_pair(0.0, 0.0);
}

std::vector<NodeData> TreeModelWrapper::getNodeData() const
{
    std::cout << "Getting node data" << std::endl;
    std::vector<NodeData> nodeData;
    for (const auto &pair : nodeMap)
    {
        int nodeId = pair.first;
        tmNode *node = pair.second;
        NodeData data;
        data.id = nodeId;
        data.x = node->GetLoc().x;
        data.y = node->GetLoc().y;
        data.label = node->GetLabel() ? node->GetLabel() : "";
        nodeData.push_back(data);
    }
    std::cout << "Retrieved data for " << nodeData.size() << " nodes" << std::endl;
    return nodeData;
}

std::vector<EdgeData> TreeModelWrapper::getEdgeData() const
{
    std::cout << "Getting edge data" << std::endl;
    std::vector<EdgeData> edgeData;
    for (const auto &pair : edgeMap)
    {
        std::cout << "EdgeMap: " << pair.first << std::endl;
        int edgeId = pair.first;
        std::cout << "Getting Edge Id (pair.first)" << edgeId << std::endl;
        tmEdge *edge = pair.second;
        std::cout << "Getting Edge Data (pair.second) " << edge << std::endl;
        EdgeData data;
        data.id = edgeId;
        std::cout << "Meow" << std::endl;
        std::cout << "Getting Node Ids "<< std::endl;
        // Get the node IDs by searching the nodeMap
        tmNode *node1 = edge->GetNodes().front();
        tmNode *node2 = edge->GetNodes().back();
        std::cout << "The nodes are:" << std::endl;
        std::cout << "\tNode1: " << node1 << std::endl;
        std::cout << "\tNode2: " << node2 << std::endl;
        data.node1Id = -1;
        data.node2Id = -1;
        std::cout << "Going through NodeMap  to get ids"<< std::endl;
        for (const auto &nodePair : nodeMap)
        {
            std::cout << "NodeMap: " << nodePair.first << std::endl;
            if (nodePair.second == node1)
                data.node1Id = nodePair.first;
            if (nodePair.second == node2)
                data.node2Id = nodePair.first;
            if (data.node1Id != -1 && data.node2Id != -1)
                break;
        }

        std::cout << "Getting Label " << std::endl;
        data.label = edge->GetLabel() ? edge->GetLabel() : "";
        
        std::cout << "Edge " << edgeId << " data: Node " << data.node1Id << " -> Node " << data.node2Id << ", Label: " << data.label << std::endl;
        edgeData.push_back(data);
    }
    std::cout << "Retrieved data for " << edgeData.size() << " edges" << std::endl;
    return edgeData;
}

tmTree *TreeModelWrapper::makeTreeBlank()
{
    cleanupAfterEdit();
    tree = tmTree::MakeTreeBlank();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;

    std::cout << "Created blank tree" << std::endl;
    return tree;
}

void TreeModelWrapper::cleanupAfterEdit()
{
    tree->CleanupAfterEdit();
}

tmTree *TreeModelWrapper::makeTreeUnoptimized()
{
    cleanupAfterEdit();
    tree = tmTree::MakeTreeUnoptimized();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i)
    {
        tmNode *node = tree->GetNodes()[i];
        int nodeIndex = node->GetIndex() - 1; // Adjust for 1-based indexing
        nodeMap[nodeIndex] = node;
        node->SetLabel(std::to_string(nodeIndex + 1).c_str()); // Set label to the 1-based index
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i)
    {
        tmEdge *edge = tree->GetEdges()[i];
        int edgeIndex = edge->GetIndex() - 1; // Adjust for 1-based indexing
        edgeMap[edgeIndex] = edge;
        edge->SetLabel(std::to_string(edgeIndex + 1).c_str()); // Set label to the 1-based index
    }
    std::cout << "Created unoptimized tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}

tmTree *TreeModelWrapper::makeTreeOptimized()
{
    cleanupAfterEdit();
    tree = tmTree::MakeTreeOptimized();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i)
    {
        tmNode *node = tree->GetNodes()[i];
        int nodeIndex = node->GetIndex() - 1; // Adjust for 1-based indexing
        nodeMap[nodeIndex] = node;
        node->SetLabel(std::to_string(nodeIndex + 1).c_str()); // Set label to the 1-based index
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i)
    {
        tmEdge *edge = tree->GetEdges()[i];
        int edgeIndex = edge->GetIndex() - 1; // Adjust for 1-based indexing
        edgeMap[edgeIndex] = edge;
        edge->SetLabel(std::to_string(edgeIndex + 1).c_str()); // Set label to the 1-based index
    }
    std::cout << "Created optimized tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}

tmTree *TreeModelWrapper::makeTreeGusset()
{
    cleanupAfterEdit();
    tree = tmTree::MakeTreeGusset();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
   // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i)
    {
        tmNode *node = tree->GetNodes()[i];
        int nodeIndex = node->GetIndex() - 1; // Adjust for 1-based indexing
        nodeMap[nodeIndex] = node;
        node->SetLabel(std::to_string(nodeIndex + 1).c_str()); // Set label to the 1-based index
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i)
    {
        tmEdge *edge = tree->GetEdges()[i];
        int edgeIndex = edge->GetIndex() - 1; // Adjust for 1-based indexing
        edgeMap[edgeIndex] = edge;
        edge->SetLabel(std::to_string(edgeIndex + 1).c_str()); // Set label to the 1-based index
    }
    std::cout << "Created gusset tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}

tmTree *TreeModelWrapper::makeTreeConditioned()
{
    cleanupAfterEdit();
    tree = tmTree::MakeTreeConditioned();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;
    // Populate nodeMap and edgeMap based on the new tree structure
    for (size_t i = 0; i < tree->GetNumNodes(); ++i)
    {
        tmNode *node = tree->GetNodes()[i];
        int nodeIndex = node->GetIndex() - 1; // Adjust for 1-based indexing
        nodeMap[nodeIndex] = node;
        node->SetLabel(std::to_string(nodeIndex + 1).c_str()); // Set label to the 1-based index
    }
    for (size_t i = 0; i < tree->GetNumEdges(); ++i)
    {
        tmEdge *edge = tree->GetEdges()[i];
        int edgeIndex = edge->GetIndex() - 1; // Adjust for 1-based indexing
        edgeMap[edgeIndex] = edge;
        edge->SetLabel(std::to_string(edgeIndex + 1).c_str()); // Set label to the 1-based index
    }
    std::cout << "Created conditioned tree with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    return tree;
}

void TreeModelWrapper::buildTreePolys()
{
    tree->BuildTreePolys();
}

bool TreeModelWrapper::isTreeOptimized() const
{
    return tree->IsFeasible();
}

void TreeModelWrapper::buildCreasePattern()
{
    if (!isTreeOptimized())
    {
        std::cerr << "Cannot build crease pattern. Tree is not optimized." << std::endl;
        return;
    }

    tree->BuildPolysAndCreasePattern();
}

bool TreeModelWrapper::hasFullCreasePattern() const
{
    return tree->HasFullCP();
}

tmTree::CPStatus TreeModelWrapper::getCreasePatternStatus(tmArray<tmEdge *> &badEdges, tmArray<tmPoly *> &badPolys,
                                                          tmArray<tmVertex *> &badVertices, tmArray<tmCrease *> &badCreases,
                                                          tmArray<tmFacet *> &badFacets)
{
    return tree->GetCPStatus(badEdges, badPolys, badVertices, badCreases, badFacets);
}

void TreeModelWrapper::getLeafNodes(tmArray<tmNode *> &aNodeList)
{
    tree->GetLeafNodes(aNodeList);
}

void TreeModelWrapper::getBorderNodes(tmArray<tmNode *> &aNodeList)
{
    tree->GetBorderNodes(aNodeList);
}

void TreeModelWrapper::getLeafPaths(tmArray<tmPath *> &aPathList)
{
    tree->GetLeafPaths(aPathList);
}

void TreeModelWrapper::getSpanningEdges(const tmArray<tmNode *> &aNodeList, tmArray<tmEdge *> &aEdgeList)
{
    tree->GetSpanningEdges(aNodeList, aEdgeList);
}

void TreeModelWrapper::getSpanningPaths(const tmArray<tmNode *> &aNodeList, tmArray<tmPath *> &aPathList)
{
    tree->GetSpanningPaths(aNodeList, aPathList);
}

void TreeModelWrapper::filterLeafNodes(tmDpptrArray<tmNode> &aNodeList)
{
    tree->FilterLeafNodes(aNodeList);
}

void TreeModelWrapper::filterMovableParts(tmDpptrArray<tmNode> &aNodeList, tmDpptrArray<tmEdge> &aEdgeList)
{
    tree->FilterMovableParts(aNodeList, aEdgeList);
}

void TreeModelWrapper::setNodesFixedToSymmetryLine(const tmArray<tmNode *> &nodes)
{
    tree->SetNodesFixedToSymmetryLine(nodes);
}

void TreeModelWrapper::setNodesFixedToPaperEdge(const tmArray<tmNode *> &nodes)
{
    tree->SetNodesFixedToPaperEdge(nodes);
}

void TreeModelWrapper::setNodesFixedToPaperCorner(const tmArray<tmNode *> &nodes)
{
    tree->SetNodesFixedToPaperCorner(nodes);
}

void TreeModelWrapper::setNodesFixedToPosition(const tmArray<tmNode *> &nodes, bool xFixed, tmFloat xFixValue,
                                               bool yFixed, tmFloat yFixValue)
{
    tree->SetNodesFixedToPosition(nodes, xFixed, xFixValue, yFixed, yFixValue);
}

void TreeModelWrapper::setEdgesSameStrain(const tmArray<tmEdge *> &edges)
{
    tree->SetEdgesSameStrain(edges);
}

void TreeModelWrapper::setPathsActive(const tmArray<tmPath *> &paths)
{
    tree->SetPathsActive(paths);
}

void TreeModelWrapper::setPathsAngleFixed(const tmArray<tmPath *> &paths, tmFloat angle)
{
    tree->SetPathsAngleFixed(paths, angle);
}

void TreeModelWrapper::setPathsAngleQuant(const tmArray<tmPath *> &paths, size_t quant, tmFloat quantOffset)
{
    tree->SetPathsAngleQuant(paths, quant, quantOffset);
}
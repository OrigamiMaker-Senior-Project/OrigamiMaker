#include "TreeModelWrapper.h"
#include <QDebug>
#include <iostream>
#include "mainwindow.h"
#include "tmModel/tmNode.h"
#include "tmModel/tmEdge.h"

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

void TreeModelWrapper::connectSignals(QObject *receiver)
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(receiver);
    if (mainWindow) {
        connect(this, &TreeModelWrapper::treeUpdated, mainWindow, &MainWindow::onTreeUpdated);
    }
}

tmNode* TreeModelWrapper::createNode(double x, double y, tmNode* parentNode)
{
    cleanupAfterEdit();
    tmNode* newNode;
    tmEdge* newEdge;
    try
    {
        tree->AddNode(parentNode == nullptr ? nullptr : parentNode, tmPoint(x, y), newNode, newEdge);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error creating node: " << e.what() << std::endl;
        return nullptr;
    }

    int nodeId = nextNodeId++;
    nodeMap[nodeId] = newNode;
    std::cout << "Created node with ID: " << nodeId << std::endl;
    //strcpy(newNode->mLabel, std::to_string(nodeId).c_str());
    //std::cout << "Node label: " << newNode->mLabel << std::endl;

    if (newEdge != nullptr)
    {
        int edgeId = nextEdgeId++;
        edgeMap[edgeId] = newEdge;
        std::cout << "Created edge with ID: " << edgeId << std::endl;
        //strcpy(newEdge->mLabel, std::to_string(edgeId).c_str());
        //std::cout << "Edge label: " << newEdge->mLabel << std::endl;
    }

    std::cout << "Node count: " << tree->GetNumNodes() << std::endl;
    return newNode;
}

void TreeModelWrapper::createNodesFromList(const std::vector<std::pair<double, double>>& nodePositions)
{
    std::cout << "Creating nodes from list..." << std::endl;
    
    tmNode* parentNode = nullptr;
    for (const auto& pos : nodePositions)
    {
        std::cout << "Creating node at (" << pos.first << ", " << pos.second << ")" << std::endl;
        tmNode* newNode = createNode(pos.first, pos.second, parentNode);
        if (newNode != nullptr)
        {
            parentNode = newNode;
        }
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
        //data.label = node->GetLabel() ? node->GetLabel() : "";
        nodeData.push_back(data);
    }
    std::cout << "Retrieved data for " << nodeData.size() << " nodes" << std::endl;
    return nodeData;
}

std::vector<EdgeData> TreeModelWrapper::getEdgeData() const
{
    std::cout << "Getting edge data" << std::endl;
    std::vector<EdgeData> edgeData;
    std::cout << "EdgeMap size: " << edgeMap.size() << std::endl;
    for (const auto& pair : edgeMap)
    {
        std::cout << "Inside EdgeMap" << std::endl;
        int edgeId = pair.first;
        tmEdge* edge = pair.second;
        EdgeData data;
        data.id = edgeId;
        std::cout << "Getting Nodes for Edge ID: " << edgeId << std::endl;
        
        // Check if the edge pointer is valid
        if (edge == nullptr) {
            std::cout << "Edge pointer is null for Edge ID: " << edgeId << std::endl;
            continue;
        }
        
        // Check if the front node is valid
        tmNode* frontNode = edge->GetNodes().front();
        if (frontNode == nullptr) {
            std::cout << "Front node is null for Edge ID: " << edgeId << std::endl;
            continue;
        }
        
        // Check if the back node is valid
        tmNode* backNode = edge->GetNodes().back();
        if (backNode == nullptr) {
            std::cout << "Back node is null for Edge ID: " << edgeId << std::endl;
            continue;
        }
        
        
        if (frontNode != nullptr && backNode != nullptr)
        {
            data.node1Id = frontNode->GetIndex();
            data.node2Id = backNode->GetIndex();
            //data.label = edge->GetLabel() ? edge->GetLabel() : "";
            edgeData.push_back(data);
        }
    }
    std::cout << "Retrieved data for " << edgeData.size() << " edges" << std::endl;
    return edgeData;
}


void TreeModelWrapper::cleanupAfterEdit()
{
    tree->CleanupAfterEdit();
}

tmTree* TreeModelWrapper::createTreeFromList(const std::vector<std::pair<double, double>>& nodePositions)
{
    std::cout << "Creating tree from list..." << std::endl;
    cleanupAfterEdit();
    tree = new tmTree();
    nodeMap.clear();
    edgeMap.clear();
    nextNodeId = 1;
    nextEdgeId = 1;

    createNodesFromList(nodePositions);

    if (tree != nullptr)
    {
        std::cout << "Created tree from list with " << tree->GetNumNodes() << " nodes and " << tree->GetNumEdges() << " edges" << std::endl;
    }
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

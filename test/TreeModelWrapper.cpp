#include "TreeModelWrapper.h"
#include <QDebug>
#include <iostream>
#include "mainwindow.h"
#include "tmModel/tmNode.h"
#include "tmModel/tmEdge.h"
#include "tmModel/tmModel_fwd.h"
#include "tmModel/tmScaleOptimizer.h"
#include "tmModel/tmStrainOptimizer.h"
#include "tmModel/tmEdgeOptimizer.h"

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
    /*
    if (!isTreeOptimized())
    {
        std::cerr << "Cannot build crease pattern. Tree is not optimized." << std::endl;
        return;
    }
    */
    std::cout << "building crease pattern and polys" << std::endl;
    tree->BuildPolysAndCreasePattern();
    std::cout << "built!!!!!!!!!" << std::endl;
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


void TreeModelWrapper::optimizeTree()
{
    // Perform scale optimization
    scaleOptimization();

    // Perform strain optimization
    strainOptimization();

    // Perform edge optimization on all nodes and edges
    tmDpptrArray<tmNode> allNodes = tree->GetNodes();
    tmDpptrArray<tmEdge> allEdges = tree->GetEdges();


    edgeOptimization(allNodes, allEdges);
}


void TreeModelWrapper::scaleOptimization()
{
    tmNLCO* theNLCO = tmNLCO::MakeNLCO();
    tmScaleOptimizer* theOptimizer = new tmScaleOptimizer(tree, theNLCO);
    theOptimizer->Initialize();

    try {
        theOptimizer->Optimize();
    } catch (const tmNLCO::EX_BAD_CONVERGENCE&) {
        std::cout << "Scale optimization failed: " << std::endl;
    }

    delete theOptimizer;
    delete theNLCO;
}

void TreeModelWrapper::strainOptimization()
{
    tmNLCO* theNLCO = tmNLCO::MakeNLCO();
    tmStrainOptimizer* theOptimizer = new tmStrainOptimizer(tree, theNLCO);
    tmDpptrArray<tmNode> movingNodes;
    tmDpptrArray<tmEdge> stretchyEdges;
    try {
        theOptimizer->Initialize(movingNodes, stretchyEdges);
        theOptimizer->Optimize();
    } catch (const tmNLCO::EX_BAD_CONVERGENCE&) {
        std::cout << "Strain optimization failed: " << std::endl;
    } catch (const tmStrainOptimizer::EX_NO_MOVING_NODES_OR_EDGES&) {
        std::cout << "Strain optimization failed: No moving nodes or edges" << std::endl;
    }

    delete theOptimizer;
    delete theNLCO;
}

void TreeModelWrapper::edgeOptimization(tmDpptrArray<tmNode>& nodes, tmDpptrArray<tmEdge>& edges)
{
    tmNLCO* theNLCO = tmNLCO::MakeNLCO();
    tmEdgeOptimizer* theOptimizer = new tmEdgeOptimizer(tree, theNLCO);
    try {
        theOptimizer->Initialize(nodes, edges);
        theOptimizer->Optimize();
    } catch (const tmNLCO::EX_BAD_CONVERGENCE&) {
        std::cout << "Edge optimization failed: " << std::endl;
    } catch (const tmEdgeOptimizer::EX_NO_MOVING_NODES&) {
        std::cout << "Edge optimization failed: No moving nodes" << std::endl;
    } catch (const tmEdgeOptimizer::EX_NO_MOVING_EDGES&) {
        std::cout << "Edge optimization failed: No moving edges" << std::endl;
    }

    delete theOptimizer;
    delete theNLCO;
}

std::vector<std::pair<QPointF, QPointF>> TreeModelWrapper::getCreasePattern() const
{
    std::vector<std::pair<QPointF, QPointF>> creasePattern;

    // Iterate over the creases in the tree and add them to the crease pattern
    for (size_t i = 0; i < tree->GetCreases().size(); ++i) {
        tmCrease* crease = tree->GetCreases()[i];
        tmPoint p1 = crease->GetVertices().front()->GetLoc();
        tmPoint p2 = crease->GetVertices().back()->GetLoc();
        creasePattern.emplace_back(QPointF(p1.x, p1.y), QPointF(p2.x, p2.y));
    }

    return creasePattern;
}

void TreeModelWrapper::setTreeScale()
{
    tree->SetPaperWidth(1.0);
    tree->SetPaperHeight(1.0);
    tree->SetScale(1.0);
}

void TreeModelWrapper::removeStrain(tmArray<tmEdge*>& aEdgeList)
{
    tree->RemoveStrain(aEdgeList);
}

void TreeModelWrapper::removeAllStrain()
{
    tree->RemoveAllStrain();
}

void TreeModelWrapper::perturbNodes(const tmArray<tmNode*>& aNodeList)
{
    tree->PerturbNodes(aNodeList);
}

bool TreeModelWrapper::canPerturbAllNodes() const
{
    return tree->CanPerturbAllNodes();
}

void TreeModelWrapper::perturbAllNodes()
{
    tree->PerturbAllNodes();
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


//tests

void TreeModelWrapper::testCreateTreeFromList(TreeModelWrapper& wrapper, const std::vector<std::pair<double, double>>& nodePositions)
{
    qDebug() << "Creating tree from list...";
    tmTree* tree = wrapper.createTreeFromList(nodePositions);
    if (tree)
    {
        qDebug() << "Node count:" << wrapper.getNodeCount();
        qDebug() << "Edge count:" << wrapper.getEdgeCount();
    }
    else
    {
        qDebug() << "Failed to create tree from list";
    }
}

void TreeModelWrapper::testGetNodeAndEdgeData(TreeModelWrapper& wrapper)
{
    // Test getting node data
    std::vector<NodeData> nodeData = wrapper.getNodeData();
    qDebug() << "Node data:";
    for (const auto& data : nodeData)
    {
        qDebug() << "  Node" << data.id << ": (" << data.x << "," << data.y << "), Label:" << QString::fromStdString(data.label);
    }

    // Test getting edge data
    std::vector<EdgeData> edgeData = wrapper.getEdgeData();
    qDebug() << "Edge data:";
    for (const auto& data : edgeData)
    {
        qDebug() << "  Edge" << data.id << ": Node" << data.node1Id << "-> Node" << data.node2Id << ", Label:" << QString::fromStdString(data.label);
    }
}

void TreeModelWrapper::testCreasePattern(TreeModelWrapper& wrapper)
{
    // Test creating a crease pattern
    qDebug() << "Creating a crease pattern...";
    qDebug() << "Is tree optimized?" << (wrapper.isTreeOptimized() ? "Yes" : "No");

    if (!wrapper.isTreeOptimized())
    {
        wrapper.buildCreasePattern();


        qDebug() << "Has full crease pattern?" << (wrapper.hasFullCreasePattern() ? "Yes" : "No");

        if (wrapper.hasFullCreasePattern())
        {
            tmArray<tmEdge*> badEdges;
            tmArray<tmPoly*> badPolys;
            tmArray<tmVertex*> badVertices;
            tmArray<tmCrease*> badCreases;
            tmArray<tmFacet*> badFacets;
            tmTree::CPStatus cpStatus = wrapper.getCreasePatternStatus(badEdges, badPolys, badVertices, badCreases, badFacets);
            qDebug() << "Crease pattern status:" << cpStatus;
        }
        else
        {
            qDebug() << "Failed to create a full crease pattern.";
        }
    }
    else
    {
        qDebug() << "EHTree is not optimized. Cannot create a crease pattern.";
    }
}

void TreeModelWrapper::runTests()
{
    TreeModelWrapper wrapper;
    qDebug() << "TreeModelWrapper test";

    // Test creating trees from lists of node positions
    /*
    std::vector<std::pair<double, double>> blankPositions = {
        {0.2, 0.2},
        {0.4, 0.4},
        {0.6, 0.6},
        {0.8, 0.8}
    };
    qDebug() << "Creating blank tree";
    testCreateTreeFromList(wrapper, blankPositions);

    std::vector<std::pair<double, double>> unoptimizedPositions = {
        {0.4, 0.8},
        {0.45, 0.6},
        {0.55, 0.35},
        {0.55, 0.01},
        {0.05, 0.95},
        {0.95, 0.95},
        {0.05, 0.05},
        {0.95, 0.05}
    };
    qDebug() << "Creating unoptimized tree";
    testCreateTreeFromList(wrapper, unoptimizedPositions);

    std::vector<std::pair<double, double>> gussetPositions = {
        {0.0, 0.0},
        {0.45, 0.5},
        {1.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0}
    };
    qDebug() << "Creating gusset tree";
    testCreateTreeFromList(wrapper, gussetPositions);

    std::vector<std::pair<double, double>> conditionedPositions = {
        {0.5, 0.1},
        {0.6, 0.5},
        {0.65, 0.75},
        {0.05, 0.05},
        {1.0, 0.5},
        {0.05, 0.95},
        {1.0, 1.0},
        {0.5, 0.85}
    };
    qDebug() << "Creating conditioned tree";
    testCreateTreeFromList(wrapper, conditionedPositions);




    */
    std::vector<std::pair<double, double>> optimizedPositions = {
        {0.5, 0.812792},
        {0.45, 0.6},
        {0.52, 0.48},
        {0.55, 0.35},
        {0.5, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {0.0, 0.187208},
        {1.0, 0.187208}
    };

    qDebug() << "Creating optimized tree";


    //qDebug() << "Getting node and edge data test";
    // Test getting node and edge data
    // testGetNodeAndEdgeData(wrapper);

    testCreateTreeFromList(wrapper, optimizedPositions);
    tree->mIsFeasible = true;
    qDebug() << "Creating a crease pattern!!!!";
    // Test creating a crease pattern
    testCreasePattern(wrapper);

    qDebug() << "TreeModelWrapper test complete";
}

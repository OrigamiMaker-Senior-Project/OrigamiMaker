#include "TreeModelWrapper.h"
#include <iostream>

void testCreateTree(TreeModelWrapper &wrapper, const std::string &treeName)
{
    std::cout << "Creating " << treeName << " tree..." << std::endl;
    tmTree *tree = nullptr;
    if (treeName == "blank")
        tree = wrapper.makeTreeBlank();
    else if (treeName == "unoptimized")
        tree = wrapper.makeTreeUnoptimized();
    else if (treeName == "optimized")
        tree = wrapper.makeTreeOptimized();
    else if (treeName == "gusset")
        tree = wrapper.makeTreeGusset();
    else if (treeName == "conditioned")
        tree = wrapper.makeTreeConditioned();

    if (tree)
    {
        std::cout << "Node count: " << tree->GetNumNodes() << std::endl;
        std::cout << "Edge count: " << tree->GetNumEdges() << std::endl;
    }
    else
    {
        std::cout << "Invalid tree type: " << treeName << std::endl;
    }
}

void testAddNodesToTree(TreeModelWrapper &wrapper, const std::string &treeName)
{
    std::cout << "Adding nodes and edges to the " << treeName << " tree..." << std::endl;
    int node1Id = wrapper.createNode(0.2, 0.2);
    int node2Id = wrapper.createNode(0.4, 0.4, node1Id);
    std::cout << "Node count: " << wrapper.getNodeCount() << std::endl;
    std::cout << "Edge count: " << wrapper.getEdgeCount() << std::endl;
}

void testSplitEdge(TreeModelWrapper &wrapper, int edgeId, double splitRatio)
{
    std::cout << "Splitting edge " << edgeId << " with ratio " << splitRatio << std::endl;
    int newNodeId = wrapper.splitEdge(edgeId, splitRatio);
    if (newNodeId != -1)
    {
        std::cout << "New node created with ID: " << newNodeId << std::endl;
    }
    else
    {
        std::cout << "Failed to split edge" << std::endl;
    }
}

void testGetNodeAndEdgeData(TreeModelWrapper &wrapper)
{
    // Test getting node data
    std::vector<NodeData> nodeData = wrapper.getNodeData();
    std::cout << "Node data:" << std::endl;
    for (const auto &data : nodeData)
    {
        std::cout << "  Node " << data.id << ": (" << data.x << ", " << data.y << "), Label: " << data.label << std::endl;
    }

    // Test getting edge data
    std::vector<EdgeData> edgeData = wrapper.getEdgeData();
    std::cout << "Edge data:" << std::endl;
    for (const auto &data : edgeData)
    {
        std::cout << "  Edge " << data.id << ": Node " << data.node1Id << " -> Node " << data.node2Id << ", Label: " << data.label << std::endl;
    }
}

void testSetNodeAndEdgeLabels(TreeModelWrapper &wrapper)
{
    // Get valid node and edge IDs from the wrapper
    std::vector<NodeData> nodeData = wrapper.getNodeData();
    std::vector<EdgeData> edgeData = wrapper.getEdgeData();

    if (!nodeData.empty())
    {
        int node1Id = nodeData[0].id;
        wrapper.setNodeLabel(node1Id, "Node 1");
    }

    if (nodeData.size() >= 2)
    {
        int node2Id = nodeData[1].id;
        wrapper.setNodeLabel(node2Id, "Node 2");
    }

    if (!edgeData.empty())
    {
        int edge1Id = edgeData[0].id;
        wrapper.setEdgeLabel(edge1Id, "Edge 1");
    }
}

void testGetNodePositions(TreeModelWrapper &wrapper)
{
    // Get valid node IDs from the wrapper
    std::vector<NodeData> nodeData = wrapper.getNodeData();

    if (nodeData.size() >= 2)
    {
        int node1Id = nodeData[0].id;
        int node2Id = nodeData[1].id;

        std::pair<double, double> node1Pos = wrapper.getNodePosition(node1Id);
        std::pair<double, double> node2Pos = wrapper.getNodePosition(node2Id);

        std::cout << "Node " << node1Id << " position: (" << node1Pos.first << ", " << node1Pos.second << ")" << std::endl;
        std::cout << "Node " << node2Id << " position: (" << node2Pos.first << ", " << node2Pos.second << ")" << std::endl;
    }
}

void testCreasePattern(TreeModelWrapper &wrapper)
{
    // Test creating a crease pattern
    std::cout << "Creating a crease pattern..." << std::endl;
    tmTree *cpTree = wrapper.makeTreeOptimized();
    std::cout << "Is tree optimized? " << (wrapper.isTreeOptimized() ? "Yes" : "No") << std::endl;

    if (wrapper.isTreeOptimized())
    {
        wrapper.buildCreasePattern();
        std::cout << "Has full crease pattern? " << (wrapper.hasFullCreasePattern() ? "Yes" : "No") << std::endl;

        if (wrapper.hasFullCreasePattern())
        {
            tmArray<tmEdge *> badEdges;
            tmArray<tmPoly *> badPolys;
            tmArray<tmVertex *> badVertices;
            tmArray<tmCrease *> badCreases;
            tmArray<tmFacet *> badFacets;
            tmTree::CPStatus cpStatus = wrapper.getCreasePatternStatus(badEdges, badPolys, badVertices, badCreases, badFacets);
            std::cout << "Crease pattern status: " << cpStatus << std::endl;
        }
        else
        {
            std::cout << "Failed to create a full crease pattern." << std::endl;
        }
    }
    else
    {
        std::cout << "Tree is not optimized. Cannot create a crease pattern." << std::endl;
    }
}

int main()
{
    TreeModelWrapper wrapper;
    std::cout << "TreeModelWrapper test" << std::endl;
    // Test creating different types of trees
    testCreateTree(wrapper, "blank");
    testCreateTree(wrapper, "unoptimized");
    testCreateTree(wrapper, "optimized");
    testCreateTree(wrapper, "gusset");
    testCreateTree(wrapper, "conditioned");

    std::cout << "Adding nodes and edges" << std::endl;
    // Test adding nodes and edges to trees
    testAddNodesToTree(wrapper, "blank");
    testAddNodesToTree(wrapper, "unoptimized");
    testAddNodesToTree(wrapper, "optimized");
    testAddNodesToTree(wrapper, "gusset");
    testAddNodesToTree(wrapper, "conditioned");

    // Test splitting an edge (optional)
    bool testSplitEdgeEnabled = false;
    if (testSplitEdgeEnabled)
    {
        std::cout << "Splitting edge" << std::endl;
        testSplitEdge(wrapper, 1, 0.5);
    }

    std::cout << "Getting node and edge data" << std::endl;
    // Test getting node and edge data
    testGetNodeAndEdgeData(wrapper);

    std::cout << "Setting node and edge labels" << std::endl;
    // Test setting node and edge labels
    testSetNodeAndEdgeLabels(wrapper);

    std::cout << "Getting node positions" << std::endl;
    // Test getting node positions
    testGetNodePositions(wrapper);

    std::cout << "Creating a crease pattern" << std::endl;
    // Test creating a crease pattern
    testCreasePattern(wrapper);

    std::cout << "TreeModelWrapper test complete" << std::endl;
    return 0;
}
#include "TreeModelWrapper.h"
#include <iostream>

void testCreateTreeFromList(TreeModelWrapper& wrapper, const std::vector<std::pair<double, double>>& nodePositions)
{
    std::cout << "Creating tree from list..." << std::endl;
    tmTree* tree = wrapper.createTreeFromList(nodePositions);
    if (tree)
    {
        std::cout << "Node count: " << wrapper.getNodeCount() << std::endl;
        std::cout << "Edge count: " << wrapper.getEdgeCount() << std::endl;
    }
    else
    {
        std::cout << "Failed to create tree from list" << std::endl;
    }
}

void testGetNodeAndEdgeData(TreeModelWrapper& wrapper)
{
    // Test getting node data
    std::vector<NodeData> nodeData = wrapper.getNodeData();
    std::cout << "Node data:" << std::endl;
    for (const auto& data : nodeData)
    {
        //std::cout << "  Node " << data.id << ": (" << data.x << ", " << data.y << "), Label: " << data.label << std::endl;
    }

    // Test getting edge data
    std::vector<EdgeData> edgeData = wrapper.getEdgeData();
    std::cout << "Edge data:" << std::endl;
    for (const auto& data : edgeData)
    {
        //std::cout << "  Edge " << data.id << ": Node " << data.node1Id << " -> Node " << data.node2Id << ", Label: " << data.label << std::endl;
    }
}

void testCreasePattern(TreeModelWrapper& wrapper)
{
    // Test creating a crease pattern
    std::cout << "Creating a crease pattern..." << std::endl;
    std::cout << "Is tree optimized? " << (wrapper.isTreeOptimized() ? "Yes" : "No") << std::endl;

    if (wrapper.isTreeOptimized())
    {
        wrapper.buildCreasePattern();
        std::cout << "Has full crease pattern? " << (wrapper.hasFullCreasePattern() ? "Yes" : "No") << std::endl;

        if (wrapper.hasFullCreasePattern())
        {
            tmArray<tmEdge*> badEdges;
            tmArray<tmPoly*> badPolys;
            tmArray<tmVertex*> badVertices;
            tmArray<tmCrease*> badCreases;
            tmArray<tmFacet*> badFacets;
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

    // Test creating trees from lists of node positions
    
    std::vector<std::pair<double, double>> blankPositions = {
        {0.2, 0.2},
        {0.4, 0.4},
        {0.6, 0.6},
        {0.8, 0.8}
    };
    std::cout << "Creating blank tree" << std::endl;
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
    std::cout << "Creating unoptimized tree" << std::endl;
    testCreateTreeFromList(wrapper, unoptimizedPositions);

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
    std::cout << "Creating optimized tree" << std::endl;
    testCreateTreeFromList(wrapper, optimizedPositions);

    std::vector<std::pair<double, double>> gussetPositions = {
        {0.0, 0.0},
        {0.45, 0.5},
        {1.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0}
    };
    std::cout << "Creating gusset tree" << std::endl;
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
    std::cout << "Creating conditioned tree" << std::endl;
    testCreateTreeFromList(wrapper, conditionedPositions);

    std::cout << "Getting node and edge data test" << std::endl;
    // Test getting node and edge data
    //testGetNodeAndEdgeData(wrapper);

    std::cout << "Creating a crease pattern" << std::endl;
    // Test creating a crease pattern
    testCreasePattern(wrapper);

    std::cout << "TreeModelWrapper test complete" << std::endl;
    return 0;
}
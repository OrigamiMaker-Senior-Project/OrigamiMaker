#include "TreeModelWrapper.h"
#include <iostream>

int main() {
    TreeModelWrapper wrapper;

    // Test creating a blank tree
    std::cout << "Creating a blank tree..." << std::endl;
    tmTree* blankTree = wrapper.makeTreeBlank();
    std::cout << "Node count: " << blankTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << blankTree->GetNumEdges() << std::endl;

    // Add more nodes if needed
    // Test adding nodes and edges to the blank tree
    std::cout << "Adding nodes and edges to the blank tree..." << std::endl;
    int blankNode1Id = wrapper.createNode(0.2, 0.2);
    int blankNode2Id = wrapper.createNode(0.4, 0.4, blankNode1Id);
    int blankNode3Id = wrapper.createNode(0.6, 0.6, blankNode2Id);
    int blankNode4Id = wrapper.createNode(0.8, 0.8, blankNode3Id);
    int blackNode5Id = wrapper.createNode(0.9, 0.9, blankNode4Id);
    std::cout << "Node count: " << blankTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << blankTree->GetNumEdges() << std::endl;

    // Test creating an unoptimized tree
    std::cout << "Creating an unoptimized tree..." << std::endl;
    tmTree* unoptimizedTree = wrapper.makeTreeUnoptimized();
    std::cout << "Node count: " << unoptimizedTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << unoptimizedTree->GetNumEdges() << std::endl;

    // Test adding nodes and edges to the unoptimized tree
    std::cout << "Adding nodes and edges to the unoptimized tree..." << std::endl;
    int unoptNode1Id = wrapper.createNode(0.1, 0.1);
    int unoptNode2Id = wrapper.createNode(0.9, 0.9, unoptNode1Id);
    std::cout << "Node count: " << unoptimizedTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << unoptimizedTree->GetNumEdges() << std::endl;

    // Test creating an optimized tree
    std::cout << "Creating an optimized tree..." << std::endl;
    tmTree* optimizedTree = wrapper.makeTreeOptimized();
    std::cout << "Node count: " << optimizedTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << optimizedTree->GetNumEdges() << std::endl;

    // Test adding nodes and edges to the optimized tree
    std::cout << "Adding nodes and edges to the optimized tree..." << std::endl;
    int optNode1Id = wrapper.createNode(0.3, 0.3);
    int optNode2Id = wrapper.createNode(0.7, 0.7, optNode1Id);
    std::cout << "Node count: " << optimizedTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << optimizedTree->GetNumEdges() << std::endl;

    // Test creating a gusset tree
    std::cout << "Creating a gusset tree..." << std::endl;
    tmTree* gussetTree = wrapper.makeTreeGusset();
    std::cout << "Node count: " << gussetTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << gussetTree->GetNumEdges() << std::endl;

    // Test adding nodes and edges to the gusset tree
    std::cout << "Adding nodes and edges to the gusset tree..." << std::endl;
    int gussetNode1Id = wrapper.createNode(0.25, 0.25);
    int gussetNode2Id = wrapper.createNode(0.75, 0.75, gussetNode1Id);
    std::cout << "Node count: " << gussetTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << gussetTree->GetNumEdges() << std::endl;

    // Test creating a conditioned tree
    std::cout << "Creating a conditioned tree..." << std::endl;
    tmTree* conditionedTree = wrapper.makeTreeConditioned();
    std::cout << "Node count: " << conditionedTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << conditionedTree->GetNumEdges() << std::endl;

    // Test adding nodes and edges to the conditioned tree
    std::cout << "Adding nodes and edges to the conditioned tree..." << std::endl;
    int condNode1Id = wrapper.createNode(0.15, 0.15);
    int condNode2Id = wrapper.createNode(0.85, 0.85, condNode1Id);
    int condEdge1Id = wrapper.splitEdge(1, 0.5);
    std::cout << "Node count: " << conditionedTree->GetNumNodes() << std::endl;
    std::cout << "Edge count: " << conditionedTree->GetNumEdges() << std::endl;

    // Test getting node data
    std::vector<NodeData> nodeData = wrapper.getNodeData();
    std::cout << "Node data:" << std::endl;
    for (const auto& data : nodeData) {
        std::cout << "  Node " << data.id << ": (" << data.x << ", " << data.y << "), Label: " << data.label << std::endl;
    }

    // Test getting edge data
    std::vector<EdgeData> edgeData = wrapper.getEdgeData();
    std::cout << "Edge data:" << std::endl;
    for (const auto& data : edgeData) {
        std::cout << "  Edge " << data.id << ": Node " << data.node1Id << " -> Node " << data.node2Id << ", Label: " << data.label << std::endl;
    }

    // Test setting node labels
    wrapper.setNodeLabel(blankNode1Id, "Blank Node 1");
    wrapper.setNodeLabel(unoptNode1Id, "Unoptimized Node 1");
    wrapper.setNodeLabel(optNode1Id, "Optimized Node 1");
    wrapper.setNodeLabel(gussetNode1Id, "Gusset Node 1");
    wrapper.setNodeLabel(condNode1Id, "Conditioned Node 1");

    // Test setting edge labels
    wrapper.setEdgeLabel(condEdge1Id, "Conditioned Edge 1");

    // Test getting node positions
    std::pair<double, double> blankNode1Pos = wrapper.getNodePosition(blankNode1Id);
    std::pair<double, double> unoptNode1Pos = wrapper.getNodePosition(unoptNode1Id);
    std::pair<double, double> optNode1Pos = wrapper.getNodePosition(optNode1Id);
    std::pair<double, double> gussetNode1Pos = wrapper.getNodePosition(gussetNode1Id);
    std::pair<double, double> condNode1Pos = wrapper.getNodePosition(condNode1Id);

    // Print node positions
    std::cout << "Blank Node 1 position: (" << blankNode1Pos.first << ", " << blankNode1Pos.second << ")" << std::endl;
    std::cout << "Unoptimized Node 1 position: (" << unoptNode1Pos.first << ", " << unoptNode1Pos.second << ")" << std::endl;
    std::cout << "Optimized Node 1 position: (" << optNode1Pos.first << ", " << optNode1Pos.second << ")" << std::endl;
    std::cout << "Gusset Node 1 position: (" << gussetNode1Pos.first << ", " << gussetNode1Pos.second << ")" << std::endl;
    std::cout << "Conditioned Node 1 position: (" << condNode1Pos.first << ", " << condNode1Pos.second << ")" << std::endl;

    return 0;
}
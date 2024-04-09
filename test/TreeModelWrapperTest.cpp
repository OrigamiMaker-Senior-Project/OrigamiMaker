#include "TreeModelWrapper.h"
#include <iostream>

int main() {
    TreeModelWrapper wrapper;

    // Test creating nodes
    int node1Id = wrapper.createNode(0.0, 0.0);
    if (node1Id == -1) {
        std::cout << "Error creating node 1" << std::endl;
        return 1;
    }
    std::cout << "Created node 1 with ID: " << node1Id << std::endl;

    int node2Id = wrapper.createNode(1.0, 0.0);
    if (node2Id == -1) {
        std::cout << "Error creating node 2" << std::endl;
        return 1;
    }
    std::cout << "Created node 2 with ID: " << node2Id << std::endl;

    int node3Id = wrapper.createNode(0.5, 1.0);
    if (node3Id == -1) {
        std::cout << "Error creating node 3" << std::endl;
        return 1;
    }
    std::cout << "Created node 3 with ID: " << node3Id << std::endl;

    // Test creating edges
    int edge1Id = wrapper.createEdge(node1Id, node2Id);
    if (edge1Id == -1) {
        std::cout << "Error creating edge 1" << std::endl;
        return 1;
    }
    std::cout << "Created edge 1 with ID: " << edge1Id << std::endl;

    int edge2Id = wrapper.createEdge(node2Id, node3Id);
    if (edge2Id == -1) {
        std::cout << "Error creating edge 2" << std::endl;
        return 1;
    }
    std::cout << "Created edge 2 with ID: " << edge2Id << std::endl;

    int edge3Id = wrapper.createEdge(node3Id, node1Id);
    if (edge3Id == -1) {
        std::cout << "Error creating edge 3" << std::endl;
        return 1;
    }
    std::cout << "Created edge 3 with ID: " << edge3Id << std::endl;

    // Test setting labels
    wrapper.setNodeLabel(node1Id, "Node 1");
    wrapper.setNodeLabel(node2Id, "Node 2");
    wrapper.setNodeLabel(node3Id, "Node 3");
    wrapper.setEdgeLabel(edge1Id, "Edge 1");
    wrapper.setEdgeLabel(edge2Id, "Edge 2");
    wrapper.setEdgeLabel(edge3Id, "Edge 3");

    // Test getting counts
    std::cout << "Node count: " << wrapper.getNodeCount() << std::endl;
    std::cout << "Edge count: " << wrapper.getEdgeCount() << std::endl;

    // Test getting node positions
    std::pair<double, double> node1Pos = wrapper.getNodePosition(node1Id);
    std::pair<double, double> node2Pos = wrapper.getNodePosition(node2Id);
    std::pair<double, double> node3Pos = wrapper.getNodePosition(node3Id);
    std::cout << "Node 1 position: (" << node1Pos.first << ", " << node1Pos.second << ")" << std::endl;
    std::cout << "Node 2 position: (" << node2Pos.first << ", " << node2Pos.second << ")" << std::endl;
    std::cout << "Node 3 position: (" << node3Pos.first << ", " << node3Pos.second << ")" << std::endl;

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

    return 0;
}
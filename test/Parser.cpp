#include "Parser.h"

std::vector<std::pair<double, double>> Parser::parsePointsAndEdges(const QVector<QPoint> &points, const QVector<QPair<int, int>> &edges)
{
    std::vector<std::pair<double, double>> nodePositions;

    // Add points to nodePositions
    for (const auto &point : points) {
        nodePositions.emplace_back(point.x(), point.y());
    }

    // Create edges by updating nodePositions
    for (const auto &edge : edges) {
        int node1Index = edge.first;
        int node2Index = edge.second;

        // Add an empty node position between the connected nodes
        if (node2Index - node1Index > 1) {
            double x = (nodePositions[node1Index].first + nodePositions[node2Index].first) / 2.0;
            double y = (nodePositions[node1Index].second + nodePositions[node2Index].second) / 2.0;
            nodePositions.insert(nodePositions.begin() + node1Index + 1, std::make_pair(x, y));
        }
    }

    return nodePositions;
}

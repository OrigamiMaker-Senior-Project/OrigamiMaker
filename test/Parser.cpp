#include "Parser.h"
#include <QDebug>

std::vector<std::pair<double, double>> Parser::parsePointsAndEdges(const QVector<QPoint> &points, const QVector<QPair<int, int>> &edges)
{
    std::vector<std::pair<double, double>> nodePositions;

    // Parse node positions from points
    for (const QPoint &point : points) {
        double x = static_cast<double>(point.x());
        double y = static_cast<double>(point.y());
        nodePositions.emplace_back(x, y);
    }

    // Parse edges and create additional nodes if necessary
    for (const QPair<int, int> &edge : edges) {
        int node1Index = edge.first;
        int node2Index = edge.second;

        // Check if the node indices are valid
        if (node1Index < 0 || node1Index >= points.size() ||
            node2Index < 0 || node2Index >= points.size()) {
            qDebug() << "Invalid edge indices:" << node1Index << node2Index;
            continue;
        }

        // Get the node positions for the edge
        const QPoint &node1Pos = points[node1Index];
        const QPoint &node2Pos = points[node2Index];

        // Check if the nodes are the same
        if (node1Pos == node2Pos) {
            qDebug() << "Edge connects the same node:" << node1Index;
            continue;
        }

        // Check if the edge already exists
        bool edgeExists = false;
        for (const std::pair<double, double> &nodePos : nodePositions) {
            if (nodePos.first == node1Pos.x() && nodePos.second == node1Pos.y()) {
                for (const std::pair<double, double> &otherNodePos : nodePositions) {
                    if (otherNodePos.first == node2Pos.x() && otherNodePos.second == node2Pos.y()) {
                        edgeExists = true;
                        break;
                    }
                }
                break;
            }
        }

        if (!edgeExists) {
            // Add the edge nodes to the node positions
            nodePositions.emplace_back(node1Pos.x(), node1Pos.y());
            nodePositions.emplace_back(node2Pos.x(), node2Pos.y());
        }
    }

    return nodePositions;
}

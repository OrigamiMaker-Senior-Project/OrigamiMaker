#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QPoint>
#include <QPair>
#include "TreeModelWrapper.h"

class Parser
{
public:
    static std::vector<std::pair<double, double>> parsePointsAndEdges(const QVector<QPoint> &points, const QVector<QPair<int, int>> &edges);
};

#endif // PARSER_H

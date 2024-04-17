#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>


class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = nullptr);

    QVector<QPoint> getPoints() const { return points; }
    QVector<QPair<int, int>> getEdges() const { return edges; }

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QVector<QPoint> points;
    QVector<QPair<int, int>> edges;
    int currentPointIndex;
    bool isDrawingEdge;
    QPoint currentEdgeEndPoint;
    QVector<int> selectedPoints;
    QVector<QPair<int, int>> selectedEdges;
    int movingPointIndex;
    bool isMovingPoint;

    void selectPoint(int index);
    void deselectPoint(int index);
    void selectEdge(const QPair<int, int>& edge);
    void deselectEdge(const QPair<int, int>& edge);
    void deleteSelectedPoints();
    void deleteSelectedEdges();
    int findNearestPoint(const QPoint& pos) const;
    QPair<int, int> findNearestEdge(const QPoint& pos) const;
    bool isPointSelected(int index) const;
    bool isEdgeSelected(const QPair<int, int>& edge) const;
    void movePoint(int index, const QPoint& newPos);
    void updateConnectedEdges(int pointIndex);

signals:
    void treeUpdated();
};

#endif // CANVASWIDGET_H

#include "CanvasWidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <cmath>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget{parent}, currentPointIndex(-1), isDrawingEdge(false),
    movingPointIndex(-1), isMovingPoint(false)
{}

void CanvasWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Set color & size of points
    painter.setBrush(Qt::black);
    int pointSize = 6;

    // Draw all edges
    painter.setPen(QPen(Qt::gray, 2));
    for (const auto &edge : edges) {
        painter.drawLine(points[edge.first], points[edge.second]);

        // Highlight selected edges
        if (isEdgeSelected(edge)) {
            painter.setPen(QPen(Qt::blue, 4));
            painter.drawLine(points[edge.first], points[edge.second]);
            painter.setPen(QPen(Qt::gray, 2));
        }
    }

    // Draw the current edge being drawn
    if (isDrawingEdge) {
        painter.drawLine(points[currentPointIndex], currentEdgeEndPoint);
    }

    // Draw all points
    for (int i = 0; i < points.size(); ++i) {
        // Highlight selected points
        if (isPointSelected(i)) {
            painter.setBrush(Qt::blue);
            painter.drawEllipse(points[i], pointSize + 2, pointSize + 2);
            painter.setBrush(Qt::black);
        } else {
            painter.drawEllipse(points[i], pointSize, pointSize);
        }
    }
}

void CanvasWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // Check if an existing point is clicked
        int nearestPointIndex = findNearestPoint(event->pos());
        if (nearestPointIndex != -1) {
            currentPointIndex = nearestPointIndex;
            isDrawingEdge = true;
            currentEdgeEndPoint = event->pos();

            // Toggle point selection
            if (event->modifiers() & Qt::ControlModifier) {
                if (isPointSelected(currentPointIndex)) {
                    deselectPoint(currentPointIndex);
                } else {
                    selectPoint(currentPointIndex);
                }
            } else {
                if (!isPointSelected(currentPointIndex)) {
                    selectedPoints.clear();
                    selectedEdges.clear();
                    selectPoint(currentPointIndex);
                }
            }
        } else {
            // Check if an existing edge is clicked
            QPair<int, int> nearestEdge = findNearestEdge(event->pos());
            if (nearestEdge != qMakePair(-1, -1)) {
                // Toggle edge selection
                if (event->modifiers() & Qt::ControlModifier) {
                    if (isEdgeSelected(nearestEdge)) {
                        deselectEdge(nearestEdge);
                    } else {
                        selectEdge(nearestEdge);
                    }
                } else {
                    if (!isEdgeSelected(nearestEdge)) {
                        selectedPoints.clear();
                        selectedEdges.clear();
                        selectEdge(nearestEdge);
                    }
                }
            } else {
                // If no existing point or edge is clicked and it's the first point, add a new point
                if (points.isEmpty()) {
                    points.append(event->pos());
                    currentPointIndex = points.size() - 1;
                    selectedPoints.clear();
                    selectedEdges.clear();
                    selectPoint(currentPointIndex);
                    isDrawingEdge = true;
                    currentEdgeEndPoint = event->pos();
                } else {
                    selectedPoints.clear();
                    selectedEdges.clear();
                }
            }
        }

        update();
    }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event) {
    if (isDrawingEdge) {
        currentEdgeEndPoint = event->pos();
        update();
    } else if (isMovingPoint) {
        movePoint(movingPointIndex, event->pos());
        updateConnectedEdges(movingPointIndex);
        update();
    }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (isDrawingEdge) {
        // Check if the edge is released on an existing point
        int nearestPointIndex = findNearestPoint(event->pos());
        if (nearestPointIndex != -1 && nearestPointIndex != currentPointIndex) {
            QPair<int, int> newEdge(currentPointIndex, nearestPointIndex);
            if (!edges.contains(newEdge) && !edges.contains(qMakePair(nearestPointIndex, currentPointIndex))) {
                edges.append(newEdge);
                emit treeUpdated();
            }
        } else if (nearestPointIndex == -1) {
            // If the edge is not released on an existing point, add a new point
            points.append(event->pos());
            QPair<int, int> newEdge(currentPointIndex, points.size() - 1);
            edges.append(newEdge);
            emit treeUpdated();
        }
        isDrawingEdge = false;
        update();
    } else if (isMovingPoint) {
        isMovingPoint = false;
    }
}

void CanvasWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    // Check if an existing point is double-clicked
    int nearestPointIndex = findNearestPoint(event->pos());
    if (nearestPointIndex != -1) {
        movingPointIndex = nearestPointIndex;
        isMovingPoint = true;
    }
}

void CanvasWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete || event->key() == Qt::Key_Backspace) {
        deleteSelectedPoints();
        deleteSelectedEdges();
        emit treeUpdated();
        update();
    } else if (event->key() == Qt::Key_A && event->modifiers() & Qt::ControlModifier) {
        selectedPoints.clear();
        selectedEdges.clear();
        for (int i = 0; i < points.size(); ++i) {
            selectPoint(i);
        }
        for (const auto &edge : edges) {
            selectEdge(edge);
        }
        update();
    }
}

void CanvasWidget::selectPoint(int index) {
    if (!isPointSelected(index)) {
        selectedPoints.append(index);
    }
}

void CanvasWidget::deselectPoint(int index) {
    selectedPoints.removeOne(index);
}

void CanvasWidget::selectEdge(const QPair<int, int>& edge) {
    if (!isEdgeSelected(edge)) {
        selectedEdges.append(edge);
    }
}

void CanvasWidget::deselectEdge(const QPair<int, int>& edge) {
    selectedEdges.removeOne(edge);
}

void CanvasWidget::deleteSelectedPoints() {
    // Sort the selected points in descending order
    std::sort(selectedPoints.begin(), selectedPoints.end(), std::greater<int>());

    // Remove selected points from the points vector
    for (int index : selectedPoints) {
        points.remove(index);
    }

    // Update the edges after removing points
    for (int i = 0; i < edges.size(); ++i) {
        auto &edge = edges[i];
        if (selectedPoints.contains(edge.first) || selectedPoints.contains(edge.second)) {
            edges.remove(i);
            --i;
        } else {
            for (int j = 0; j < selectedPoints.size(); ++j) {
                if (edge.first > selectedPoints[j]) {
                    --edge.first;
                }
                if (edge.second > selectedPoints[j]) {
                    --edge.second;
                }
            }
        }
    }

    selectedPoints.clear();
}

void CanvasWidget::deleteSelectedEdges() {
    for (const auto &edge : selectedEdges) {
        edges.removeOne(edge);
    }

    selectedEdges.clear();
}

int CanvasWidget::findNearestPoint(const QPoint& pos) const {
    int nearestIndex = -1;
    qreal minDistance = 10.0; // Minimum distance threshold

    for (int i = 0; i < points.size(); ++i) {
        qreal distance = QLineF(pos, points[i]).length();
        if (distance < minDistance) {
            nearestIndex = i;
            minDistance = distance;
        }
    }

    return nearestIndex;
}

QPair<int, int> CanvasWidget::findNearestEdge(const QPoint& pos) const {
    QPair<int, int> nearestEdge = qMakePair(-1, -1);
    qreal minDistance = 10.0; // Minimum distance threshold

    for (const auto &edge : edges) {
        QLineF line(points[edge.first], points[edge.second]);

        // Calculate the nearest point on the line to 'pos'
        qreal u = ((pos.x() - line.p1().x()) * (line.p2().x() - line.p1().x()) + (pos.y() - line.p1().y()) * (line.p2().y() - line.p1().y())) / line.length() / line.length();
        u = qMax(0.0, qMin(1.0, u)); // Clamp 'u' to the 0.0 to 1.0 range
        QPointF nearestPointOnLine = line.pointAt(u);

        // Calculate the distance from 'pos' to the nearest point on the line
        qreal distance = QLineF(pos, nearestPointOnLine).length();

        if (distance < minDistance) {
            nearestEdge = edge;
            minDistance = distance;
        }
    }

    return nearestEdge;
}


bool CanvasWidget::isPointSelected(int index) const {
    return selectedPoints.contains(index);
}

bool CanvasWidget::isEdgeSelected(const QPair<int, int>& edge) const {
    return selectedEdges.contains(edge) || selectedEdges.contains(qMakePair(edge.second, edge.first));
}

void CanvasWidget::movePoint(int index, const QPoint& newPos) {
    if (index >= 0 && index < points.size()) {
        points[index] = newPos;
        emit treeUpdated();
    }
}

void CanvasWidget::updateConnectedEdges(int pointIndex) {
    for (auto &edge : edges) {
        if (edge.first == pointIndex) {
            edge.second = pointIndex;
        } else if (edge.second == pointIndex) {
            edge.first = pointIndex;
        }
    }
}

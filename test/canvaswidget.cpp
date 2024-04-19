#include "CanvasWidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <cmath>
#include <QDebug>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget{parent}, currentPointIndex(-1), isDrawingEdge(false),
    movingPointIndex(-1), isMovingPoint(false)
{
    setFocusPolicy(Qt::StrongFocus);
    installEventFilter(this);
}

bool CanvasWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Delete || keyEvent->key() == Qt::Key_Backspace) {
                if (!selectedPoints.isEmpty() || !selectedEdges.isEmpty()) {
                    deleteSelectedPoints();
                    deleteSelectedEdges();
                    emit treeUpdated();
                    update();
                    return true;
                }
            } else if (keyEvent->matches(QKeySequence::SelectAll)) {
                selectedPoints.clear();
                selectedEdges.clear();
                for (int i = 0; i < points.size(); ++i) {
                    selectPoint(i);
                }
                for (const auto &edge : edges) {
                    selectEdge(edge);
                }
                update();
                return true;
            }
        }
    }
    return QWidget::eventFilter(watched, event);
}

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
            if (event->modifiers() & Qt::ShiftModifier) {
                // Start moving the point if Shift is pressed
                movingPointIndex = nearestPointIndex;
                isMovingPoint = true;
            } else {
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
        QPoint offset = event->pos() - points[movingPointIndex];
        for (int i = 0; i < points.size(); ++i) {
            if (isPointSelected(i)) {
                movePoint(i, points[i] + offset);
            }
        }
        updateConnectedEdges();
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
    QVector<QPoint> oldPoints = points;
    QVector<QPair<int, int>> oldEdges = edges;

    QVector<int> pointsToDelete = selectedPoints;

    // Sort the points to delete in descending order
    std::sort(pointsToDelete.begin(), pointsToDelete.end(), std::greater<int>());

    // Find all edges connected to the selected points
    QVector<QPair<int, int>> edgesToDelete;
    for (const auto &edge : edges) {
        if (selectedPoints.contains(edge.first) || selectedPoints.contains(edge.second)) {
            edgesToDelete.append(edge);
        }
    }

    // Delete the selected points and their associated edges
    for (int index : pointsToDelete) {
        deletePoint(index);
    }
    for (const auto &edge : edgesToDelete) {
        deleteEdge(edge);
    }

    selectedPoints.clear();

    if (!isTreeConnected()) {
        qDebug() << "Deleting the selected points will create an incomplete tree!";
        points = oldPoints;
        edges = oldEdges;
        emit deletionReverted();
    }
}

void CanvasWidget::deleteSelectedEdges() {
    QVector<QPoint> oldPoints = points;
    QVector<QPair<int, int>> oldEdges = edges;

    QVector<QPair<int, int>> edgesToDelete = selectedEdges;

    // Find all points connected to the selected edges
    QVector<int> pointsToDelete;
    for (const auto &edge : edgesToDelete) {
        if (!pointsToDelete.contains(edge.first)) {
            pointsToDelete.append(edge.first);
        }
        if (!pointsToDelete.contains(edge.second)) {
            pointsToDelete.append(edge.second);
        }
    }

    // Delete the selected edges and their connected points
    for (const auto &edge : edgesToDelete) {
        deleteEdge(edge);
    }
    for (int index : pointsToDelete) {
        deletePoint(index);
    }

    selectedEdges.clear();

    if (!isTreeConnected()) {
        qDebug() << "Deleting the selected edges will create an incomplete tree!";
        points = oldPoints;
        edges = oldEdges;
        emit deletionReverted();
    }
}

bool CanvasWidget::isLeafNode(int pointIndex) const {
    int edgeCount = 0;
    for (const auto &edge : edges) {
        if (edge.first == pointIndex || edge.second == pointIndex) {
            ++edgeCount;
            if (edgeCount > 1) {
                return false;
            }
        }
    }
    return true;
}

bool CanvasWidget::isTreeConnected() const {
    if (points.isEmpty()) {
        return true;
    }

    QVector<bool> visited(points.size(), false);
    QVector<int> stack;
    stack.append(0);
    visited[0] = true;

    while (!stack.isEmpty()) {
        int currentPoint = stack.takeLast();
        for (const auto &edge : edges) {
            int otherPoint = -1;
            if (edge.first == currentPoint) {
                otherPoint = edge.second;
            } else if (edge.second == currentPoint) {
                otherPoint = edge.first;
            }

            if (otherPoint != -1 && !visited[otherPoint]) {
                stack.append(otherPoint);
                visited[otherPoint] = true;
            }
        }
    }

    return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
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
    qDebug() << "Moving point" << index << "to" << newPos;
    if (index >= 0 && index < points.size()) {
        points[index] = newPos;
        emit treeUpdated();
        update();
    }
}

void CanvasWidget::updateConnectedEdges() {
    qDebug() << "Updating connected edges";
    for (auto &edge : edges) {
        edge.first = points.indexOf(points[edge.first]);
        edge.second = points.indexOf(points[edge.second]);
    }
    update();
}
void CanvasWidget::deletePoint(int index) {
    if (index >= 0 && index < points.size()) {
        points.remove(index);

        // Update the edges after removing the point
        for (int i = 0; i < edges.size(); ++i) {
            auto &edge = edges[i];
            if (edge.first == index || edge.second == index) {
                edges.remove(i);
                --i;
            } else {
                if (edge.first > index) {
                    --edge.first;
                }
                if (edge.second > index) {
                    --edge.second;
                }
            }
        }
    }
}

void CanvasWidget::deleteEdge(const QPair<int, int>& edge) {
    edges.removeOne(edge);
}

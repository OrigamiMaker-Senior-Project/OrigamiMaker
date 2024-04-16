#include "CanvasWidget.h"
#include <QPainter>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget{parent}, currentPointIndex(-1), isDrawingEdge(false)
{}

void CanvasWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Set color & size of points
    painter.setBrush(Qt::black);
    int pointSize = 5;

    // Draw all edges
    painter.setPen(QPen(Qt::gray, 1));
    for (const auto &edge : edges) {
        painter.drawLine(points[edge.first], points[edge.second]);
    }

    // Draw all points
    for (int i = 0; i < points.size(); ++i) {
        painter.drawEllipse(points[i], pointSize, pointSize);
    }
}

void CanvasWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // Check if an existing point is clicked
        for (int i = 0; i < points.size(); ++i) {
            if (QRect(points[i] - QPoint(5, 5), QSize(10, 10)).contains(event->pos())) {
                currentPointIndex = i;
                isDrawingEdge = true;
                break;
            }
        }

        // If no existing point is clicked, add a new point
        if (!isDrawingEdge) {
            points.append(event->pos());
            currentPointIndex = points.size() - 1;
        }

        update();
    }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event) {
    if (isDrawingEdge) {
        // Update the canvas to show the edge being drawn
        update();
    }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (isDrawingEdge) {
        // Check if the edge is released on an existing point
        for (int i = 0; i < points.size(); ++i) {
            if (QRect(points[i] - QPoint(5, 5), QSize(10, 10)).contains(event->pos())) {
                if (i != currentPointIndex) {
                    edges.append(qMakePair(currentPointIndex, i));
                    emit treeUpdated();
                }
                break;
            }
        }

        isDrawingEdge = false;
        update();
    }
}

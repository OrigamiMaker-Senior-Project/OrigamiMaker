#include "CanvasWidget.h"
#include <QPainter>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget{parent}
{}

void CanvasWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Set color & size of points
    painter.setBrush(Qt::black);
    int pointSize = 5;          // Adjust the size as needed

    // Draw all points
    for (int i = 0; i < points.size(); ++i) {
        painter.drawEllipse(points[i], pointSize, pointSize);

        // Draw lines between consecutive points
        if (i > 0) {
            painter.drawLine(points[i - 1], points[i]);
        }
    }
}

void CanvasWidget::mousePressEvent(QMouseEvent *event) {
    // Add clicked point to the list
    points.append(event->pos());
    // Trigger a repaint to update the canvas
    update();
}

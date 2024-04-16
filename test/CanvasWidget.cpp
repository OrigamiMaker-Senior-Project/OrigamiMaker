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
    int pointSize = 5;
    // Draw all points
    for (int i = 0; i < points.size(); ++i) {

        // Draw lines between consecutive points
        if (i > 0) {
            // Set line color & width
            painter.setPen(QPen(Qt::gray, 1));
            painter.drawLine(points[i - 1], points[i]);
        }

        if (i != 0)
            painter.drawEllipse(points[i-1], pointSize, pointSize);     //re-draws previous point so it's on top of line
        painter.drawEllipse(points[i], pointSize, pointSize);       //draw new point
    }
}

void CanvasWidget::mousePressEvent(QMouseEvent *event) {
    // Add clicked point to the list
    points.append(event->pos());
    // Trigger a repaint to update the canvas
    update();
}

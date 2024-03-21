#include "canvaswidget.h"

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // Draw your canvas content here using the QPainter
    // For example, you can draw a simple rectangle:
    painter.fillRect(rect(), Qt::white);
}

CanvasWidget::~CanvasWidget()
{
    // Clean up any resources or memory
}

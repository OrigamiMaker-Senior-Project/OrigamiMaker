#include "canvaswidget.h"
#include <QPainter>
#include <QMouseEvent>
#include "./tmModel/tmNode.h"
#include "./tmModel/tmEdge.h"

CanvasWidget::CanvasWidget(QWidget* parent)
    : QWidget(parent), mDoc(nullptr), mDesignFrame(nullptr)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

CanvasWidget::~CanvasWidget()
{
}

void CanvasWidget::setDoc(tmDoc* doc)
{
    mDoc = doc;
}

void CanvasWidget::setDesignFrame(tmwxDesignFrame* aFrame)
{
    mDesignFrame = aFrame;
}

void CanvasWidget::setSize(const QSize& aSize)
{
    setFixedSize(aSize);
}

tmTree* CanvasWidget::getTree() const
{
    return mDoc->GetTree();
}


void CanvasWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw nodes
    for (const auto& node : getTree()->GetNodes()) {
        drawPart(painter, node, false);
    }

    // Draw edges
    for (const auto& edge : getTree()->GetEdges()) {
        drawPart(painter, edge, false);
    }
}

QPoint CanvasWidget::treeToDC(const tmPoint& fp) const
{
    // Implement the coordinate transformation from tmPoint to QPoint
    // based on the original wxWidgets implementation
    int x = static_cast<int>(fp.x);
    int y = static_cast<int>(fp.y);
    return QPoint(x, y);
}

tmPoint CanvasWidget::dcToTree(const QPoint& p) const
{
    // Implement the coordinate transformation from QPoint to tmPoint
    // based on the original wxWidgets implementation
    tmFloat x = static_cast<tmFloat>(p.x());
    tmFloat y = static_cast<tmFloat>(p.y());
    return tmPoint(x, y);
}

void CanvasWidget::drawDot(QPainter& painter, const QPoint& loc, const QColor& theColor, int theWidth) const
{
    painter.setPen(QPen(theColor, theWidth));
    painter.drawEllipse(loc, theWidth / 2, theWidth / 2);
}

template <>
void CanvasWidget::drawPart<tmNode>(QPainter& painter, tmNode* aNode, bool isSelected) const
{
    // Implement the drawing of tmNode based on the original wxWidgets implementation
    QColor theColor = isSelected ? QColor(255, 0, 0) : QColor(0, 0, 255);
    int theWidth = isSelected ? 6 : 4;
    QPoint cloc = treeToDC(aNode->GetLoc());
    drawDot(painter, cloc, theColor, theWidth);
}

template <>
void CanvasWidget::drawPart<tmEdge>(QPainter& painter, tmEdge* aEdge, bool isSelected) const
{
    // Implement the drawing of tmEdge based on the original wxWidgets implementation
    QColor theColor = isSelected ? QColor(255, 0, 0) : QColor(0, 255, 0);
    int theWidth = isSelected ? 3 : 2;
    QPoint p1 = treeToDC(aEdge->GetNodes().front()->GetLoc());
    QPoint p2 = treeToDC(aEdge->GetNodes().back()->GetLoc());
    painter.setPen(QPen(theColor, theWidth));
    painter.drawLine(p1, p2);
}

bool CanvasWidget::clickOnPoint(const QPoint& where, const tmPoint& q) const
{
    // Implement the logic to check if a click occurred on a point
    // based on the original wxWidgets implementation
    QPoint cloc = treeToDC(q);
    int dx = where.x() - cloc.x();
    int dy = where.y() - cloc.y();
    return (dx * dx + dy * dy) <= 16;
}

bool CanvasWidget::clickOnLine(const QPoint& where, const tmPoint& q1, const tmPoint& q2) const
{
    // Implement the logic to check if a click occurred on a line
    // based on the original wxWidgets implementation
    QPoint p1 = treeToDC(q1);
    QPoint p2 = treeToDC(q2);
    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();
    int lengthSquared = dx * dx + dy * dy;
    if (lengthSquared == 0)
        return false;
    int t = ((where.x() - p1.x()) * dx + (where.y() - p1.y()) * dy) / lengthSquared;
    if (t < 0 || t > 1)
        return false;
    int dist = ((where.x() - p1.x()) * dy - (where.y() - p1.y()) * dx) / sqrt(lengthSquared);
    return abs(dist) <= 4;
}

template <class P>
P* CanvasWidget::clickOn(const QPoint& where) const
{
    // Implement the logic to handle clicks on different parts
    // based on the original wxWidgets implementation
    for (const auto& part : getTree()->GetParts<P>()) {
        if (clickOnPoint(where, part->GetLoc()))
            return part;
    }
    return nullptr;
}

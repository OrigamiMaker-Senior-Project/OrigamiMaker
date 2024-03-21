#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QPainter>
#include "./tmModel/tmTree.h"
#include "./tmModel/tmNode.h"
#include "./tmModel/tmEdge.h"
#include "./tmModel/tmPart.h"
#include "tmDoc.h"

// Forward declarations
class tmwxDesignFrame;

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(QWidget* parent = nullptr);
    ~CanvasWidget();

    void setDoc(tmDoc* doc);
    void setDesignFrame(tmwxDesignFrame* aFrame);
    void setSize(const QSize& aSize);

    // tmTree object drawing
    tmTree* getTree() const;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    tmDoc* mDoc;
    tmwxDesignFrame* mDesignFrame;

    // Coordinate transformation (both drawing and mousing)
    QPoint treeToDC(const tmPoint& fp) const;
    tmPoint dcToTree(const QPoint& p) const;

    // Drawing
    void drawDot(QPainter& painter, const QPoint& loc, const QColor& theColor, int theWidth) const;
    template <class P>
    void drawPart(QPainter& painter, P* p, bool isSelected) const;

    // Mousing
    bool clickOnPoint(const QPoint& where, const tmPoint& q) const;
    bool clickOnLine(const QPoint& where, const tmPoint& q1, const tmPoint& q2) const;
    template <class P>
    P* clickOn(const QPoint& where) const;
};

// Template specializations for drawPart
template <>
void CanvasWidget::drawPart<tmNode>(QPainter& painter, tmNode* aNode, bool isSelected) const;

template <>
void CanvasWidget::drawPart<tmEdge>(QPainter& painter, tmEdge* aEdge, bool isSelected) const;

#endif // CANVASWIDGET_H

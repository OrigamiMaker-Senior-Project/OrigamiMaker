#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QPainter>
#include "./tmModel/tmTree.h" // Assuming tmTree.h is available

// Forward declarations
class tmwxDoc; // Replace with appropriate class name
class tmwxDesignFrame; // Replace with appropriate class name

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(tmwxDesignFrame* aFrame, const QSize& aSize, QWidget* parent = nullptr);
    ~CanvasWidget();

    // View settings
    // const tmwxViewSettings& getViewSettings() const; // Replace tmwxViewSettings with appropriate class
    // tmwxViewSettings& getEditableViewSettings(); // Replace tmwxViewSettings with appropriate class
    // void setViewSettings(const tmwxViewSettings& viewSettings); // Replace tmwxViewSettings with appropriate class

    // tmTree object drawing
    tmTree* getTree() const;

    // Paper size
    qreal getPaperSize() const;
    void setPaperSize(const qreal& newPaperSize);

    bool isFitPaperSize() const;
    bool isFitPaperWidth() const;
    bool isFitPaperHeight() const;

    void fitPaperSize();
    void fitPaperWidth();
    void fitPaperHeight();

    // Printing
    void setPrinting(bool printing);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    tmwxDoc* mDoc; // Replace with appropriate class name
    tmwxDesignFrame* mDesignFrame; // Replace with appropriate class name
    // tmwxViewSettings mViewSettings; // Replace tmwxViewSettings with appropriate class

    enum FittingType {
        FITTING_SIZE = 0,
        FITTING_WIDTH,
        FITTING_HEIGHT
    };

    int mBorderScrollWidth; // width of frame borders & scroll bar
    int mBorderScrollHeight; // height of frame borders & scroll bar
    qreal mPaperSize; // size of the paper in inches
    qreal mPaperSizeScreen; // size of the paper in screen pixels
    qreal mPaperSizeDC; // size of the paper in DC pixels
    qreal mDCScale; // scaling factor from screen to DC
    int mFontW, mFontH, mFontD; // dimensions of font used for most text
    QPoint mDragStart; // beginning of a drag
    QPoint mDragOffset; // offset of a drag
    bool mDragging; // true if we're dragging
    bool mPrinting; // true if we're printing
    QVector<const tmNode*> mMovingNodes; // nodes that get dragged

    // Paper size
    void calcBorderScrollSize();
    void updatePaperSize();
    bool isFitPaper(FittingType fitting) const;
    void fitPaper(FittingType fitting);

    // Coordinate transformation (both drawing and mousing)
    void getImageSizeScreen(int& width, int& height) const;
    int pixelsToDC(int i) const;
    int pixelsToDC(qreal f) const;
    int treeToDC(qreal f) const;
    QPoint treeToDC(const tmPoint& fp) const; // Assuming tmPoint is available
    qreal dcToTree(int i) const;
    tmPoint dcToTree(const QPoint& p) const; // Assuming tmPoint is available
    template <class P>
    bool isVisible(P* p) const;

    // Calculation of location
    template <class P>
    tmPoint calcLoc(const P* p) const; // Assuming tmPoint is available
    template <class P>
    tmPoint calcLocP(const tmPart* p) const; // Assuming tmPoint and tmPart are available
    typedef tmPoint (CanvasWidget::*CalcLocFn)(const tmPart*); // Assuming tmPoint and tmPart are available

    template <class P>
    class CalcLocFnT {
    public:
        CalcLocFn operator()() const;
    };
    static QVector<CalcLocFn>& getCalcLocFns();

    tmPoint calcLocOffset(const tmPoint& p, qreal angle) const; // Assuming tmPoint is available
    tmPoint calcLocOffset(const tmPoint& p1, const tmPoint& p2, bool up) const; // Assuming tmPoint is available
    tmPoint calcLocOffset(const tmPoint& p1, const tmPoint& p2, const tmPoint& p3) const; // Assuming tmPoint is available

    // Drawing
    class Text {};
    class Lines {};
    class Fill {};
    QColor hiliteColor(const QColor& theColor, bool isSelected) const;
    template <class S>
    QColor tweakColor(const QColor& theColor) const;
    template <class P>
    QColor getBasePartColor(P* p) const; // Replace P with appropriate class
    template <class S, class P>
    QColor getPartColor(P* p, bool isSelected) const; // Replace P with appropriate class
    void drawDot(QPainter& painter, const QPoint& loc, const QColor& theColor, int theWidth) const;
    template <class S>
    void drawPaper(QPainter& painter) const;
    template <class S, class P>
    void drawPart(QPainter& painter, P* p, bool isSelected) const; // Replace P with appropriate class

    template <class P>
    void drawConditionText(QPainter& painter, tmPart* p, const QPoint& cloc) const; // Assuming tmPart is available
    typedef void (CanvasWidget::*DrawConditionTextFn)(QPainter&, tmPart*, const QPoint&); // Assuming tmPart is available
    template <class P>
    class DrawConditionTextFnT {
    public:
        DrawConditionTextFn operator()() const;
    };
    static QVector<DrawConditionTextFn>& getDrawConditionTextFns();

    template <class P>
    void drawConditionLines(QPainter& painter, tmPart* p, bool isSelected, const QPoint& cloc) const; // Assuming tmPart is available
    typedef void (CanvasWidget::*DrawConditionLinesFn)(QPainter&, tmPart*, bool, const QPoint&); // Assuming tmPart is available
    template <class P>
    class DrawConditionLinesFnT {
    public:
        DrawConditionLinesFn operator()() const;
    };
    static QVector<DrawConditionLinesFn>& getDrawConditionLinesFns();

    template <class S, class P>
    void drawAllParts(QPainter& painter, const QVector<P*>& partList) const; // Replace P with appropriate class

    // Mousing
    bool clickOnPoint(const QPoint& where, const tmPoint& q) const; // Assuming tmPoint is available
    bool clickOnLine(const QPoint& where, const tmPoint& q1, const tmPoint& q2) const; // Assuming tmPoint is available
    template <class P>
    P* clickOn(const QPoint& where) const; // Replace P with appropriate class

    // Friends
    template <class P>
    friend class CalcLocFnT;
    template <class P>
    friend class DrawConditionTextFnT;
    template <class P>
    friend class DrawConditionLinesFnT;
};

// Template function declarations
template <class P>
tmPoint CanvasWidget::calcLoc(const P* p) const;

template <class P>
tmPoint CanvasWidget::calcLocP(const tmPart* p) const;

template <class P>
QColor CanvasWidget::getBasePartColor(P* p) const;

template <class S, class P>
QColor CanvasWidget::getPartColor(P* p, bool isSelected) const;

template <class S>
void CanvasWidget::drawPaper(QPainter& painter) const;

template <class S, class P>
void CanvasWidget::drawPart(QPainter& painter, P* p, bool isSelected) const;

template <class P>
void CanvasWidget::drawConditionText(QPainter& painter, tmPart* p, const QPoint& cloc) const;

template <class P>
void CanvasWidget::drawConditionLines(QPainter& painter, tmPart* p, bool isSelected, const QPoint& cloc) const;

template <class S, class P>
void CanvasWidget::drawAllParts(QPainter& painter, const QVector<P*>& partList) const;

template <class P>
P* CanvasWidget::clickOn(const QPoint& where) const;

#endif // CANVASWIDGET_H

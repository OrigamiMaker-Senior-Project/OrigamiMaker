#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QImage>
#include <QPixmap>
#include <QLabel>

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = nullptr);

    QVector<QPoint> getPoints() const { return points; }
    QVector<QPair<int, int>> getEdges() const { return edges; }
    void drawCreasePattern(const std::vector<std::pair<QPointF, QPointF>>& creasePattern);
    void createDemoTree();
    void drawDemoCreasePattern();
    QImage getDemoCreasePatternImage() const { return demoCreasePatternImage; }

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

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
    QImage demoCreasePatternImage;

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
    void updateConnectedEdges();
    bool isLeafNode(int pointIndex) const;
    void deletePoint(int index);
    void deleteEdge(const QPair<int, int>& edge);
    bool isTreeConnected() const;

signals:
    void treeUpdated();
    void deletionReverted();
    void demoCreasePatternGenerated(const QImage& image);
};

#endif // CANVASWIDGET_H

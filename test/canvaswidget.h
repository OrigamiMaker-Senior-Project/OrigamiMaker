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
    bool isLeafNode(int pointIndex) const;
    void deletePoint(int index);
    void deleteEdge(const QPair<int, int>& edge);

signals:
    void treeUpdated();
};

#endif // CANVASWIDGET_H

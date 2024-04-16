#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QMouseEvent>

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

private:
    QVector<QPoint> points;
    QVector<QPair<int, int>> edges;
    int currentPointIndex;
    bool isDrawingEdge;

signals:
    void treeUpdated();
};

#endif // CANVASWIDGET_H

#ifndef PAINTCANVAS_H
#define PAINTCANVAS_H

#include <QWidget>
#include <QPoint>
#include <QImage>
#include <QColor>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QPainter>

class PaintCanvas : public QWidget
{
    Q_OBJECT
public:
    enum ToolType {Pen, Rect, Ellipse, Eraser};

    ToolType getTool() const;
    void setTool(const ToolType &value);
    explicit PaintCanvas(QWidget *parent = nullptr);

    bool getFill() const;
    void setFill(bool newFill);

    int getPenWidth() const;
    void setPenWidth(int newPenWidth);

    QColor getFillColor() const;
    void setFillColor(const QColor &newFillColor);

    QColor getPenColor() const;
    void setPenColor(const QColor &newPenColor);

signals:

private:
    void resizeImage(QImage *image, const QSize &newSize);

    ToolType tool;
    bool fill;
    bool drawing;
    int penWidth;
    QColor fillColor;
    QColor penColor;
    QPoint lastPoint;
    QImage image;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
};

#endif // PAINTCANVAS_H

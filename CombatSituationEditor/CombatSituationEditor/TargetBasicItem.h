#ifndef TARGETBASICITEM_H
#define TARGETBASICITEM_H

#include <QGraphicsItem>
#include <QPainter>

class TargetBasicItem : public QGraphicsItem
{
    private:
        int targetNum;
        const qreal multiplier = 1.5;
        const qreal thickness = 0.4;
    public:
        TargetBasicItem(int tNum);

        int getTargetNum() const;

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        // QGraphicsItem interface
protected:
        //void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // TARGETBASICITEM_H

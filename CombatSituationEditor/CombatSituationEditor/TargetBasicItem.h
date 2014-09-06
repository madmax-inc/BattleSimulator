#ifndef TARGETBASICITEM_H
#define TARGETBASICITEM_H

#include <QGraphicsItem>
#include <QPainter>

class TargetBasicItem : public QGraphicsItem
{
    private:
        int targetNum;
    public:
        TargetBasicItem(int tNum);

        int getTargetNum() const;

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TARGETBASICITEM_H

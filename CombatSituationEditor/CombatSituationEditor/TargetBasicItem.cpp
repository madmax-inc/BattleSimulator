#include "TargetBasicItem.h"
#include <QPen>
#include <QBrush>
#include <QDebug>

TargetBasicItem::TargetBasicItem(int tNum) : QGraphicsItem(), targetNum(tNum)
{
    //setAcceptedMouseButtons();
}

int TargetBasicItem::getTargetNum() const {
    return targetNum;
}

QRectF TargetBasicItem::boundingRect() const
{

    return QRectF(-1 * multiplier - thickness, -1 * multiplier - thickness, 3 * multiplier + thickness, 2 * multiplier + thickness);
}

void TargetBasicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    static const QPointF airplane[] =
        {
            QPointF(0, 0),
            QPointF(-1 * multiplier, -1 * multiplier),
            QPointF(2 * multiplier, 0),
            QPointF(-1 * multiplier, 1 * multiplier),
        };

    QPen pen;
    pen.setColor(QColor(0, 0, 0, 128));
    pen.setWidthF(thickness);
    pen.setJoinStyle(Qt::RoundJoin);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(100, 170, 100, 128));

    painter->setPen(pen);
    painter->setBrush(brush);


    painter->drawPolygon(airplane, 4);
}

/*void TargetBasicItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Pressed on " << targetNum;
}*/

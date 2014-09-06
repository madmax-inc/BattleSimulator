#include "TargetBasicItem.h"
#include <QPen>
#include <QBrush>

TargetBasicItem::TargetBasicItem(int tNum) : QGraphicsItem(), targetNum(tNum)
{
}

int TargetBasicItem::getTargetNum() const {
    return targetNum;
}

QRectF TargetBasicItem::boundingRect() const
{
    const int multiplier = 20;
    const qreal adjust = 2;

    return QRectF(-1 * multiplier - adjust, -1 * multiplier - adjust, 3 * multiplier + adjust, 2 * multiplier + adjust);
}

void TargetBasicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const int multiplier = 20;
    static const QPointF airplane[] =
        {
            QPointF(0, 0),
            QPointF(-1 * multiplier, -1 * multiplier),
            QPointF(2 * multiplier, 0),
            QPointF(-1 * multiplier, 1 * multiplier),
        };

    QPen pen;
    pen.setColor(QColor(0, 0, 0, 128));
    pen.setWidthF(4);
    pen.setJoinStyle(Qt::RoundJoin);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(100, 170, 100, 128));

    painter->setPen(pen);
    painter->setBrush(brush);


    painter->drawPolygon(airplane, 4);
}

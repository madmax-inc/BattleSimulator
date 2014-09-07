#include "TargetEditableItem.h"
#include <QDebug>

TargetEditableItem::TargetEditableItem(int tNum, Target& assocTarget) : TargetBasicItem(tNum), associatedTarget(assocTarget)
{

}

void TargetEditableItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Press event!";
}

void TargetEditableItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Move event!" << event->scenePos();
    associatedTarget.addOrUpdatePoint(QVector3D(event->scenePos()));
}

void TargetEditableItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Release event!";
}

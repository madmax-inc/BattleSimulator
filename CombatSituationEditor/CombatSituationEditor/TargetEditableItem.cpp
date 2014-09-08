#include "TargetEditableItem.h"
#include <QDebug>
#include <QCursor>

TargetEditableItem::TargetEditableItem(int tNum, MovementCurve<>& assocCurve, const Chronometer* chron) : TargetBasicItem(tNum), associatedCurve(assocCurve), chronos(chron)
{

}

void TargetEditableItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Press event!";
    setCursor(QCursor(Qt::ClosedHandCursor));
}

void TargetEditableItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Move event!" << event->scenePos();
    associatedCurve.addOrUpdatePoint(chronos->getCurrentTime(), QVector3D(event->scenePos()));
}

void TargetEditableItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    setCursor(QCursor(Qt::OpenHandCursor));
    qDebug() << "Release event!";
}

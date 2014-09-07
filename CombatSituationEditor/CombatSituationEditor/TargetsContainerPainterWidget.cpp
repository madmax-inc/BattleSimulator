#include "TargetsContainerPainterWidget.h"
#include "TargetBasicItem.h"
#include <QList>
#include <QGraphicsItem>
#include <cmath>
#include <QDebug>
#include "../../CommonFiles/TargetSnapshot.h"

TargetsContainerPainterWidget::TargetsContainerPainterWidget(const TargetsContainer* contain, QWidget *parent) :
    QGraphicsView(parent), container(contain), scene(this)
{
    //scene.setSceneRect(-10, -10, 20, 20);
    setScene(&scene);
    setRenderHint(QPainter::Antialiasing);
    scale(5, 5);

    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(moveTargets()));
    timer.start(25);
}

void TargetsContainerPainterWidget::containerChanged()
{
    checkAndAddItems();
    moveTargets();
}

void TargetsContainerPainterWidget::checkAndAddItems()
{
    int count = 0;
    QList<QGraphicsItem*> items = scene.items();

    for (QList<QGraphicsItem*>::iterator it = items.begin(); it != items.end(); ++it) {
        TargetBasicItem* targ = dynamic_cast<TargetBasicItem*>(*it);

        if (targ != 0) {
            count++;
        }
    }

    if (count < container->getTargetsCount()) {
        for (int i = count; i < container->getTargetsCount(); i++) {
            scene.addItem(makeTargetBasicItem(i));
        }

        moveTargets();
    }
}

TargetBasicItem *TargetsContainerPainterWidget::makeTargetBasicItem(int number) const
{
    return new TargetBasicItem(number);
}

void TargetsContainerPainterWidget::moveTargets() const
{

    QList<QGraphicsItem*> items = scene.items();

    for (QList<QGraphicsItem*>::iterator it = items.begin(); it != items.end(); ++it) {
        TargetBasicItem* targ = dynamic_cast<TargetBasicItem*>(*it);

        if (targ != 0) {
            TargetSnapshot snap = container->getTargetSnapshot(targ->getTargetNum());

            float rotationRad = -atan2(-snap.velocity.y(), snap.velocity.x());

            targ->setPos(snap.position.x(), snap.position.y());
            targ->setRotation(rotationRad*180/3.1415926);
        }
    }
}

/*
void TargetsContainerPainterWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    static const QPointF airplane[] =
        {
            QPointF(0, 0),
            QPointF(-1, -1),
            QPointF(1, 0),
            QPointF(-1, 1),
            QPointF(0, 0)
        };


    for (int i = 0; i < container.getTargetsCount(); i++) {
        TargetSnapshot target = container.getTargetSnapshot(i);

        //Проверяем, находится ли цель в зоне обзора
        if (target.position.x() >= displayArea.x() && target.position.y() >= displayArea.y() && target.position.x() <= displayArea.right() && target.position.y() <= displayArea.bottom())
            continue;

        QVector3D heading = target.velocity.normalized();

        double angleRad = atan2(-heading.y(), heading.x());

        painter.save();

        painter.restore();
    }
}
*/

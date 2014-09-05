#include "TargetsContainerPainterWidget.h"
#include <QPainter>
#include <QPointF>
#include <cmath>

TargetsContainerPainterWidget::TargetsContainerPainterWidget(QRect area, const TargetsContainer& contain, QWidget *parent) :
    QWidget(parent), displayArea(area), container(contain)
{
}


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

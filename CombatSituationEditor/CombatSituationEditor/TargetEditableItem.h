#ifndef TARGETEDITABLEITEM_H
#define TARGETEDITABLEITEM_H

#include <TargetBasicItem.h>
#include <QGraphicsSceneMouseEvent>
#include "../../CommonFiles/MovementCurve.h"
#include "../../CommonFiles/Chronometer.h"

class TargetEditableItem : public TargetBasicItem
{
    private:
        MovementCurve<>& associatedCurve;
        const Chronometer* chronos;

    public:
        TargetEditableItem(int tNum, MovementCurve<>& assocCurve, const Chronometer* chron);

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // TARGETEDITABLEITEM_H

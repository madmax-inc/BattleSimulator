#ifndef TARGETEDITABLEITEM_H
#define TARGETEDITABLEITEM_H

#include <TargetBasicItem.h>
#include <QGraphicsSceneMouseEvent>
#include "../../CommonFiles/Target.h"

class TargetEditableItem : public TargetBasicItem
{
    private:
        Target& associatedTarget;

    public:
        TargetEditableItem(int tNum, Target& assocTarget);

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // TARGETEDITABLEITEM_H

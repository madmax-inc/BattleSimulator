#ifndef TARGETSCONTAINERPAINTERWIDGET_H
#define TARGETSCONTAINERPAINTERWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "../../CommonFiles/TargetsContainer.h"
#include "TargetBasicItem.h"

class TargetsContainerPainterWidget : public QGraphicsView
{
    Q_OBJECT
    private:
        const TargetsContainer* container;

        QTimer timer;
        QGraphicsScene scene;

    public:
        TargetsContainerPainterWidget(const TargetsContainer* contain, QWidget *parent = 0);

        void containerChanged();

    private:
        void checkAndAddItems();

    protected:
        virtual TargetBasicItem* makeTargetBasicItem(int number) const;

    signals:

    public slots:
        virtual void moveTargets() const;
};

#endif // TARGETSCONTAINERPAINTERWIDGET_H

#ifndef TARGETSCONTAINERPAINTERWIDGET_H
#define TARGETSCONTAINERPAINTERWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "../../CommonFiles/TargetsContainer.h"

class TargetsContainerPainterWidget : public QGraphicsView
{
    Q_OBJECT
    private:
        const TargetsContainer* container;

        QTimer timer;
        QGraphicsScene scene;

    public:
        TargetsContainerPainterWidget(const TargetsContainer* contain, QWidget *parent = 0);

    private:
        void checkAndAddItems();

    signals:

    public slots:
        void moveTargets();

};

#endif // TARGETSCONTAINERPAINTERWIDGET_H

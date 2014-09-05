#ifndef TARGETSCONTAINERPAINTERWIDGET_H
#define TARGETSCONTAINERPAINTERWIDGET_H

#include <QWidget>
#include <QRect>
#include <QPaintEvent>
#include "../../CommonFiles/TargetsContainer.h"

class TargetsContainerPainterWidget : public QWidget
{
    Q_OBJECT
    private:
        QRect displayArea;
        const TargetsContainer& container;
    public:
        TargetsContainerPainterWidget(QRect area, const TargetsContainer& contain, QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent* event);

    signals:

    public slots:

};

#endif // TARGETSCONTAINERPAINTERWIDGET_H

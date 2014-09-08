#ifndef COMBATSITUATIONEDITORWIDGET_H
#define COMBATSITUATIONEDITORWIDGET_H

#include "TargetsContainerPainterWidget.h"
#include <QKeyEvent>
#include <QDebug>
#include "../../CommonFiles/CombatSituation.h"

class CombatSituationEditorWidget : public TargetsContainerPainterWidget
{
    private:
        CombatSituation* container;

    public:
        CombatSituationEditorWidget(CombatSituation* contain, QWidget *parent = 0);

    protected:
        TargetBasicItem* makeTargetBasicItem(int number) const;

        // QWidget interface
    protected:
        void keyPressEvent(QKeyEvent * event) {
            switch (event->key()) {
                case Qt::Key_A:
                    container->getChronometer()->start();
                    break;
                case Qt::Key_S:
                    container->getChronometer()->pause();
                    break;
                case Qt::Key_D:
                    container->getChronometer()->resume();
                    break;
                case Qt::Key_F:
                    container->getChronometer()->stop();
                    break;
            };
        }
};

#endif // COMBATSITUATIONEDITORWIDGET_H

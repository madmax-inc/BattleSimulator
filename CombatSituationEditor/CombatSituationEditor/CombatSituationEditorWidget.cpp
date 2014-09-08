#include "combatsituationeditorwidget.h"
#include "TargetEditableItem.h"

CombatSituationEditorWidget::CombatSituationEditorWidget(CombatSituation* contain, QWidget *parent) : TargetsContainerPainterWidget(contain, parent), container(contain)
{
}

TargetBasicItem* CombatSituationEditorWidget::makeTargetBasicItem(int number) const
{
    return new TargetEditableItem(number, container->getTarget(number).getTrajectory(), container->getChronometer());
}

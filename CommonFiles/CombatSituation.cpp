#include "CombatSituation.h"


CombatSituation::CombatSituation() : TargetsContainer(), chronos()
{
}

void CombatSituation::addTarget(const Target &target)
{
    targets.push_back(target);
}

Target& CombatSituation::getTarget(int index)
{
    return targets[index];
}

void CombatSituation::clearTargets()
{
    targets.clear();
}

Chronometer* CombatSituation::getChronometer()
{
    return &chronos;
}

TargetSnapshot CombatSituation::getTargetSnapshot(int index) const
{
    TargetSnapshot snap = targets.at(index).makeSnapshot(chronos.getCurrentTime());
    return snap;
}

int CombatSituation::getTargetsCount() const
{
    return targets.size();
}

QDataStream& operator<<(QDataStream& out, const CombatSituation& b)
{
    out << b.chronos << b.targets;

    return out;
}

QDataStream& operator>>(QDataStream& in, CombatSituation& b)
{
    in >> b.chronos >> b.targets;

    return in;
}

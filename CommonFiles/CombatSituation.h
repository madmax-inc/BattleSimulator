#ifndef COMBATSITUATION_H
#define COMBATSITUATION_H

#include <QVector>
#include <QDataStream>
#include "TargetsContainer.h"
#include "Target.h"
#include "Chronometer.h"


class CombatSituation : public TargetsContainer {
    private:
        QVector<Target> targets;
        Chronometer chronos;

    public:
        CombatSituation();
        CombatSituation(quint32 maxTime);
        ~CombatSituation() {

        }

        void addTarget(const Target& target);
        Target& getTarget(int index);
        void clearTargets();

        Chronometer* getChronometer();

        TargetSnapshot getTargetSnapshot(int index) const;
        int getTargetsCount() const;

        //Serialization override
        friend QDataStream& operator<<(QDataStream& out, const CombatSituation& b);
        friend QDataStream& operator>>(QDataStream& in, CombatSituation& b);
};

#endif // COMBATSITUATION_H

#ifndef TARGET_H
#define TARGET_H

#include <QDataStream>
#include "MovementCurve.h"
#include "TargetSnapshot.h"

class Target {
    private:
        MovementCurve<> trajectory;

    public:
        Target();
        Target(MovementCurve<> trajectory);
        Target(const Target& copyThis);

        TargetSnapshot makeSnapshot(double t) const;
        MovementCurve<>& getTrajectory();

        friend QDataStream& operator<<(QDataStream& out, const Target& b);
        friend QDataStream& operator>>(QDataStream& in, Target& b);
};

#endif // TARGET_H

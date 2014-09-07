#ifndef TARGET_H
#define TARGET_H

#include <QDataStream>
#include "MovementCurve.h"
#include "TargetSnapshot.h"

class Target {
    private:
        MovementCurve<> trajectory;
        quint32 currentTime;

    public:
        Target();
        Target(MovementCurve<> trajectory);
        Target(const Target& copyThis);

        TargetSnapshot makeSnapshot(double t) const;
        TargetSnapshot makeSnapshot() const;
        MovementCurve<>& getTrajectory();
        void addOrUpdatePoint(const QVector3D& point);
        void setCurrentTime(quint32 cTime);

        friend QDataStream& operator<<(QDataStream& out, const Target& b);
        friend QDataStream& operator>>(QDataStream& in, Target& b);
};

#endif // TARGET_H

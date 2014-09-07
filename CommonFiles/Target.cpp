#include "Target.h"

Target::Target() {}

Target::Target(MovementCurve<> trajectory) : trajectory(trajectory)
{
}

Target::Target(const Target& copyThis) : trajectory(copyThis.trajectory)
{
}

TargetSnapshot Target::makeSnapshot(double t) const
{
    return trajectory(t);
}

TargetSnapshot Target::makeSnapshot() const
{
    return trajectory(currentTime);
}

MovementCurve<>& Target::getTrajectory()
{
    return trajectory;
}

void Target::addOrUpdatePoint(const QVector3D& point)
{
    trajectory.addOrUpdatePoint(currentTime, point);
}

void Target::setCurrentTime(quint32 cTime)
{
    currentTime = cTime;
}

QDataStream& operator<<(QDataStream& out, const Target& b) {
    out << b.trajectory;

    return out;
}

QDataStream& operator>>(QDataStream& in, Target& b) {
    in >> b.trajectory;

    return in;
}

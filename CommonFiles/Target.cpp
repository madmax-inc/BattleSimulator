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

MovementCurve<>& Target::getTrajectory()
{
    return trajectory;
}

QDataStream& operator<<(QDataStream& out, const Target& b) {
    out << b.trajectory;

    return out;
}

QDataStream& operator>>(QDataStream& in, Target& b) {
    in >> b.trajectory;

    return in;
}

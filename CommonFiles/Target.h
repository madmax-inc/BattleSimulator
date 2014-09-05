#ifndef TARGET_H
#define TARGET_H

#include <QDataStream>
#include "MovementCurve.h"
#include "TargetSnapshot.h"
#include "LagrangeInterpolation.h"

template <typename Interpolator = LagrangeInterpolationFunction>
class Target {
    private:
        MovementCurve<Interpolator> trajectory;

    public:
        Target();
        Target(MovementCurve<Interpolator> trajectory);
        Target(const Target& copyThis);

        TargetSnapshot makeSnapshot(double t) const;

        template <typename T> friend QDataStream& operator<<(QDataStream& out, const Target<T>& b);
        template <typename T> friend QDataStream& operator>>(QDataStream& in, Target<T>& b);
};


template <typename Interpolator>
Target<Interpolator>::Target() {}

template <typename Interpolator>
Target<Interpolator>::Target(MovementCurve<Interpolator> trajectory) : trajectory(trajectory)
{
}

template <typename Interpolator>
Target<Interpolator>::Target(const Target& copyThis) : trajectory(copyThis.trajectory)
{
}

template <typename Interpolator>
TargetSnapshot Target<Interpolator>::makeSnapshot(double t) const
{
    return trajectory(t);
}

template <typename T>
QDataStream& operator<<(QDataStream& out, const Target<T>& b) {
    out << b.trajectory;

    return out;
}

template <typename T>
QDataStream& operator>>(QDataStream& in, Target<T>& b) {
    in >> b.trajectory;

    return in;
}

#endif // TARGET_H

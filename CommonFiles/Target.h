#ifndef TARGET_H
#define TARGET_H

#include <QVector3D>
#include <QDataStream>
#include "MovementCurve.h"
#include "TargetSnapshot.h"
#include "LagrangeInterpolation.h"

template <typename Interpolator = LagrangeInterpolationFunction>
class Target {
    private:
        QVector3D startingLocation;
        MovementCurve<Interpolator> trajectory;

    public:
        Target();
        Target(QVector3D startingLocation, MovementCurve<Interpolator> trajectory);
        Target(const Target& copyThis);

        TargetSnapshot makeSnapshot(double t) const;

        template <typename T> friend QDataStream& operator<<(QDataStream& out, const Target<T>& b);
        template <typename T> friend QDataStream& operator>>(QDataStream& in, Target<T>& b);
};


template <typename Interpolator>
Target<Interpolator>::Target() {}

template <typename Interpolator>
Target<Interpolator>::Target(QVector3D startingLocation, MovementCurve<Interpolator> trajectory) : startingLocation(startingLocation), trajectory(trajectory)
{
}

template <typename Interpolator>
Target<Interpolator>::Target(const Target& copyThis) : startingLocation(copyThis.startingLocation), trajectory(copyThis.trajectory)
{
}

template <typename Interpolator>
TargetSnapshot Target<Interpolator>::makeSnapshot(double t) const
{
    return trajectory(t);
}

template <typename T>
QDataStream& operator<<(QDataStream& out, const Target<T>& b) {
    out << b.startingLocation << b.trajectory;

    return out;
}

template <typename T>
QDataStream& operator>>(QDataStream& in, Target<T>& b) {
    in >> b.startingLocation >> b.trajectory;

    return in;
}

#endif // TARGET_H

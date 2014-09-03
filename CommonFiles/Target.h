#ifndef TARGET_H
#define TARGET_H

#include <QVector3D>
#include "MovementCurve.h"
#include "TargetSnapshot.h"
#include "LagrangeInterpolation.h"

template <typename Interpolator = LagrangeInterpolationFunction>
class Target {
    private:
        QVector3D startingLocation;
        MovementCurve<Interpolator> trajectory;

    public:
        Target(QVector3D startingLocation, MovementCurve<Interpolator> trajectory);

        TargetSnapshot makeSnapshot(double t) const;
};

#endif // TARGET_H


template <typename Interpolator>
Target<Interpolator>::Target(QVector3D startingLocation, MovementCurve<Interpolator> trajectory) : startingLocation(startingLocation), trajectory(trajectory)
{
}

template <typename Interpolator>
TargetSnapshot Target<Interpolator>::makeSnapshot(double t) const
{
    return trajectory(t);
}

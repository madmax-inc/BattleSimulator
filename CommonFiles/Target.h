#ifndef TARGET_H
#define TARGET_H

#include "Geometry.h"
#include "MovementCurve.h"
#include "TargetSnapshot.h"
#include "LagrangeInterpolation.h"

template <typename Interpolator = LagrangeInterpolationFunction>
class Target {
    private:
        Vector3D startingLocation;
        MovementCurve<Interpolator> trajectory;

    public:
        Target(Vector3D startingLocation, MovementCurve<Interpolator> trajectory);

        TargetSnapshot makeSnapshot(double t) const;
};

#endif // TARGET_H


template <typename Interpolator>
Target<Interpolator>::Target(Vector3D startingLocation, MovementCurve<Interpolator> trajectory) : startingLocation(startingLocation), trajectory(trajectory)
{
}

template <typename Interpolator>
TargetSnapshot Target<Interpolator>::makeSnapshot(double t) const
{
    return trajectory(t);
}

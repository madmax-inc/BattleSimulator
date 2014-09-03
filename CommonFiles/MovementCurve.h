#ifndef MOVEMENTCURVE_H
#define MOVEMENTCURVE_H

#include "TargetSnapshot.h"
#include "InterpolationFunction.h"

template <typename Interpolator>
class MovementCurve {
    private:
        InterpolationFunction<double>* xFunction;
        InterpolationFunction<double>* yFunction;
        InterpolationFunction<double>* zFunction;
    public:
        MovementCurve();
        MovementCurve(const MovementCurve& copyThis);

        ~MovementCurve();

        void addPoint(double t, double x, double y, double z);
        void addPoint(double t, const Vector3D<double>& point);
        void deletePoint(int index);
        void clearPoints();
        int getPointsCount() const;
        /*Point3d getPoint(int id) const;*/
        TargetSnapshot interpolate(double t) const;
        TargetSnapshot operator() (double t) const;
};

template <typename Interpolator>
MovementCurve<Interpolator>::MovementCurve() : xFunction(new Interpolator()), yFunction(new Interpolator()), zFunction(new Interpolator())
{
}

template <typename Interpolator>
MovementCurve<Interpolator>::MovementCurve(const MovementCurve &copyThis) : xFunction(new Interpolator(copyThis.xFunction)), yFunction(new Interpolator(copyThis.yFunction)), zFunction(new Interpolator(copyThis.zFunction))
{
}

template <typename Interpolator>
MovementCurve<Interpolator>::~MovementCurve() {
    delete xFunction;
    delete yFunction;
    delete zFunction;
}

template <typename Interpolator>
void MovementCurve<Interpolator>::addPoint(double t, double x, double y, double z) {
    xFunction->addPoint(t, x);
    yFunction->addPoint(t, y);
    zFunction->addPoint(t, z);
}

template <typename Interpolator>
void MovementCurve<Interpolator>::addPoint(double t, const Vector3D<double> &point)
{
    xFunction->addPoint(t, point.getX());
    yFunction->addPoint(t, point.getY());
    zFunction->addPoint(t, point.getZ());
}

template <typename Interpolator>
void MovementCurve<Interpolator>::deletePoint(int index)
{
    xFunction->deletePoint(index);
    yFunction->deletePoint(index);
    zFunction->deletePoint(index);
}

template <typename Interpolator>
void MovementCurve<Interpolator>::clearPoints()
{
    xFunction->clearPoints();
    yFunction->clearPoints();
    zFunction->clearPoints();
}

template <typename Interpolator>
int MovementCurve<Interpolator>::getPointsCount() const
{
    return xFunction->getPointsCount();
}

/*Point3d MovementCurve::getPoint(int id) const
{
    return Point3d(xFunction.getPointAt(id), yFunction.getPointAt(id), zFunction.getPointAt(id));
}*/

template <typename Interpolator>
TargetSnapshot MovementCurve<Interpolator>::interpolate(double t) const {
    TargetSnapshot res =
        {
            Vector3D<double>(xFunction->interpolate(t), yFunction->interpolate(t), zFunction->interpolate(t)),
            Vector3D<double>(xFunction->interpolate(t + 1) - xFunction->interpolate(t), yFunction->interpolate(t + 1) - yFunction->interpolate(t), zFunction->interpolate(t + 1) - zFunction->interpolate(t))
        };
    return res;
}

template <typename Interpolator>
TargetSnapshot MovementCurve<Interpolator>::operator()(double t) const
{
    return interpolate(t);
}


#endif // MOVEMENTCURVE_H

#ifndef MOVEMENTCURVE_H
#define MOVEMENTCURVE_H

#include "TargetSnapshot.h"
#include "InterpolationFunction.h"
#include <QVector>
#include <QPair>
#include <QDataStream>

template <typename Interpolator>
class MovementCurve {
    private:
        InterpolationFunction* xFunction;
        InterpolationFunction* yFunction;
        InterpolationFunction* zFunction;
    public:
        MovementCurve();
        MovementCurve(const QVector<QPair<double, Vector3D> >& points);
        MovementCurve(const MovementCurve& copyThis);

        ~MovementCurve();

        void addPoint(double t, double x, double y, double z);
        void addPoint(double t, const Vector3D& point);
        void addPoints(const QVector<QPair<double, Vector3D> >& points);
        void deletePoint(int index);
        void clearPoints();
        int getPointsCount() const;
        QPair<double, Vector3D> getPointAt(int index) const;
        TargetSnapshot interpolate(double t) const;
        TargetSnapshot operator() (double t) const;

        //Serialization
        friend QDataStream& operator<<(QDataStream& out, const MovementCurve<Interpolator>& b);
        friend QDataStream& operator>>(QDataStream& in, MovementCurve<Interpolator>& b);
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
MovementCurve<Interpolator>::MovementCurve(const QVector<QPair<double, Vector3D> >& points) : MovementCurve<Interpolator>()
{
    addPoints(points);
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
void MovementCurve<Interpolator>::addPoint(double t, const Vector3D& point)
{
    xFunction->addPoint(t, point.getX());
    yFunction->addPoint(t, point.getY());
    zFunction->addPoint(t, point.getZ());
}

template <typename Interpolator>
void MovementCurve<Interpolator>::addPoints(const QVector<QPair<double, Vector3D> >& points)
{
    for (QVector<QPair<double, Vector3D> >::const_iterator it = points.begin(); it != points.end(); ++it) {
        xFunction->addPoint(it->first, it->second.getX());
        yFunction->addPoint(it->first, it->second.getY());
        zFunction->addPoint(it->first, it->second.getZ());
    }
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

template <typename Interpolator>
QPair<double, Vector3D> MovementCurve<Interpolator>::getPointAt(int index) const
{
    double t = xFunction->getPointAt(index).first;

    Vector3D resVector
        (
            xFunction->getPointAt(index).second,
            yFunction->getPointAt(index).second,
            zFunction->getPointAt(index).second
        );

    QPair <double, Vector3D> res = qMakePair<double, Vector3D>
        (
            t,
            resVector
        );

    return res;
}

template <typename Interpolator>
TargetSnapshot MovementCurve<Interpolator>::interpolate(double t) const {
    TargetSnapshot res =
        {
            Vector3D(xFunction->interpolate(t), yFunction->interpolate(t), zFunction->interpolate(t)),
            Vector3D(xFunction->interpolate(t + 1) - xFunction->interpolate(t), yFunction->interpolate(t + 1) - yFunction->interpolate(t), zFunction->interpolate(t + 1) - zFunction->interpolate(t))
        };
    return res;
}

template <typename Interpolator>
TargetSnapshot MovementCurve<Interpolator>::operator()(double t) const
{
    return interpolate(t);
}


//Serialization override
template <typename Interpolator>
QDataStream& operator<<(QDataStream& out, const MovementCurve<Interpolator>& b)
{
    out << *b.xFunction << *b.yFunction << *b.zFunction;

    return out;
}

template <typename Interpolator>
QDataStream& operator>>(QDataStream& in, MovementCurve<Interpolator>& b)
{
    in >> *b.xFunction >> *b.yFunction >> *b.zFunction;

    return in;
}


#endif // MOVEMENTCURVE_H

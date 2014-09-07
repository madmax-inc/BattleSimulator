#ifndef MOVEMENTCURVE_H
#define MOVEMENTCURVE_H

#include <QVector3D>
#include "TargetSnapshot.h"
#include "InterpolationFunction.h"
#include "LagrangeInterpolation.h"
#include <QVector>
#include <QPair>
#include <QDataStream>

template <typename Interpolator = LagrangeInterpolationFunction>
class MovementCurve {
    private:
        InterpolationFunction* xFunction;
        InterpolationFunction* yFunction;
        InterpolationFunction* zFunction;
    public:
        MovementCurve();
        MovementCurve(const QVector<QPair<double, QVector3D> >& points);
        MovementCurve(const MovementCurve& copyThis);
        MovementCurve& operator=(const MovementCurve& copythis);

        ~MovementCurve();

        void addPoint(double t, double x, double y, double z);
        void addPoint(double t, const QVector3D& point);
        void addOrUpdatePoint(double t, const QVector3D& point);
        void addPoints(const QVector<QPair<double, QVector3D> >& points);
        void deletePoint(int index);
        void clearPoints();
        int getPointsCount() const;
        QPair<double, QVector3D> getPointAt(int index) const;
        TargetSnapshot interpolate(double t) const;
        TargetSnapshot operator() (double t) const;

        //Serialization
        template <typename T> friend QDataStream& operator<<(QDataStream& out, const MovementCurve<T>& b);
        template <typename T> friend QDataStream& operator>>(QDataStream& in, MovementCurve<T>& b);
};

template <typename Interpolator>
MovementCurve<Interpolator>::MovementCurve() : xFunction(new Interpolator()), yFunction(new Interpolator()), zFunction(new Interpolator())
{
}


template <typename Interpolator>
MovementCurve<Interpolator>::MovementCurve(const MovementCurve &copyThis) : xFunction(new Interpolator(*copyThis.xFunction)), yFunction(new Interpolator(*copyThis.yFunction)), zFunction(new Interpolator(*copyThis.zFunction))
{
}

template <typename Interpolator>
MovementCurve<Interpolator>::MovementCurve(const QVector<QPair<double, QVector3D> >& points) : MovementCurve<Interpolator>()
{
    addPoints(points);
}

template <typename Interpolator>
MovementCurve<Interpolator>& MovementCurve<Interpolator>::operator=(const MovementCurve<Interpolator>& copythis) {
    if (this == &copythis) {
        return *this;
    }

    delete xFunction;
    delete yFunction;
    delete zFunction;

    xFunction = new Interpolator(*copythis.xFunction);
    yFunction = new Interpolator(*copythis.yFunction);
    zFunction = new Interpolator(*copythis.zFunction);

    return *this;
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
void MovementCurve<Interpolator>::addPoint(double t, const QVector3D& point)
{
    xFunction->addPoint(t, point.x());
    yFunction->addPoint(t, point.y());
    zFunction->addPoint(t, point.z());
}

template <typename Interpolator>
void MovementCurve<Interpolator>::addOrUpdatePoint(double t, const QVector3D &point)
{
    //FIX ME! Ахтунг! Ручной поиск точки!
    const double timeTreshold = 250;

    bool found = false;
    int pointIndex = 0;

    for (int i = 0; i < getPointsCount(); i++) {
        QPair<double, QVector3D> point = getPointAt(i);

        if (point.first >= (t - timeTreshold) && point.first <= (t + timeTreshold)) {
            found = true;
            pointIndex = i;
            break;
        }
    }

    if (found) {
        deletePoint(pointIndex);
    }

    addPoint(t, point);
}

template <typename Interpolator>
void MovementCurve<Interpolator>::addPoints(const QVector<QPair<double, QVector3D> >& points)
{
    for (QVector<QPair<double, QVector3D> >::const_iterator it = points.begin(); it != points.end(); ++it) {
        xFunction->addPoint(it->first, it->second.x());
        yFunction->addPoint(it->first, it->second.y());
        zFunction->addPoint(it->first, it->second.z());
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
QPair<double, QVector3D> MovementCurve<Interpolator>::getPointAt(int index) const
{
    double t = xFunction->getPointAt(index).first;

    QVector3D resVector
        (
            xFunction->getPointAt(index).second,
            yFunction->getPointAt(index).second,
            zFunction->getPointAt(index).second
        );

    QPair <double, QVector3D> res = qMakePair<double, QVector3D>
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
            QVector3D(xFunction->interpolate(t), yFunction->interpolate(t), zFunction->interpolate(t)),
            QVector3D(xFunction->interpolate(t + 1) - xFunction->interpolate(t), yFunction->interpolate(t + 1) - yFunction->interpolate(t), zFunction->interpolate(t + 1) - zFunction->interpolate(t))
        };
    return res;
}

template <typename Interpolator>
TargetSnapshot MovementCurve<Interpolator>::operator()(double t) const
{
    return interpolate(t);
}


//Serialization override
template <typename T>
QDataStream& operator<<(QDataStream& out, const MovementCurve<T>& b)
{
    out << *b.xFunction << *b.yFunction << *b.zFunction;

    return out;
}

template <typename T>
QDataStream& operator>>(QDataStream& in, MovementCurve<T>& b)
{
    in >> *b.xFunction >> *b.yFunction >> *b.zFunction;

    return in;
}


#endif // MOVEMENTCURVE_H

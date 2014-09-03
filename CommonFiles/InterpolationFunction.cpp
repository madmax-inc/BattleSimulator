#include "InterpolationFunction.h"

InterpolationFunction::InterpolationFunction()
{
}

InterpolationFunction::InterpolationFunction(const QVector<QPair<double, double> > &inPoints) : points(inPoints)
{
}

InterpolationFunction::InterpolationFunction(const InterpolationFunction &copyThis) : points(copyThis.points)
{
}

int InterpolationFunction::getPointsCount() const
{
    return points.size();
}

void InterpolationFunction::addPoint(double argument, double value)
{
    points.push_back(qMakePair<double, double>(argument, value));
}

void InterpolationFunction::addPoints(const QVector<QPair<double, double> >& inPoints)
{
    points << inPoints;
}

void InterpolationFunction::clearPoints() {
    points.clear();
}

void InterpolationFunction::deletePoint(int index)
{
    points.erase(points.begin()+index);
}

QPair<double, double> InterpolationFunction::getPointAt(int index) const
{
    return points[index];
}

double InterpolationFunction::operator()(double at) const
{
    return interpolate(at);
}

QDataStream& operator<<(QDataStream& out, const InterpolationFunction& b)
{
    out << b.points;

    return out;
}

QDataStream& operator>>(QDataStream& in, InterpolationFunction& b)
{
    in >> b.points;

    return in;
}

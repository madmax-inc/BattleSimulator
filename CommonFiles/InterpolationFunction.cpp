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

QPair<double, double> InterpolationFunction::calcExtremum(double from, double to, double treshold) const
{
    enum stage {
        RAISING,
        LOWERING
    };

    double minValue = interpolate(from) < interpolate(to) ? interpolate(from) : interpolate(to);
    double maxValue = interpolate(from) > interpolate(to) ? interpolate(from) : interpolate(to);

    stage s = interpolate(from) < interpolate(from + treshold) ? RAISING : LOWERING;

    for (double current = from; current <= to; current += treshold) {
        switch (s) {
            case RAISING:
                //Possible maximum
                if (interpolate(current) > interpolate(current + treshold)) {
                    if (interpolate(current + treshold/2) > maxValue)
                        maxValue = interpolate(current + treshold/2);

                    s = LOWERING;
                }
                break;
            case LOWERING:
                //Possible minimum
                if (interpolate(current) < interpolate(current + treshold)) {
                    if (interpolate(current + treshold/2) < minValue)
                        minValue = interpolate(current + treshold/2);

                    s = RAISING;
                }
                break;
        };
    }

    return qMakePair<double, double> (minValue, maxValue);
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

#include "LagrangeInterpolation.h"

LagrangeInterpolationFunction::LagrangeInterpolationFunction() : InterpolationFunction()
{
}

LagrangeInterpolationFunction::LagrangeInterpolationFunction(const QVector<QPair<double, double> > &inPoints) : InterpolationFunction(inPoints)
{
}

LagrangeInterpolationFunction::LagrangeInterpolationFunction(const InterpolationFunction &copyThis) : InterpolationFunction(copyThis)
{
}

double LagrangeInterpolationFunction::interpolate(double at) const {
    double value = 0;

    for (int i = 0; i < InterpolationFunction::getPointsCount(); i++) {
        QPair<double, double> pointI = InterpolationFunction::getPointAt(i);
        double multiplier = pointI.second;//y[i]

        for (int j = 0; j < InterpolationFunction::getPointsCount(); j++) {
            if (i == j) {
                continue;
            }

            QPair<double, double> pointJ = InterpolationFunction::getPointAt(j);

            multiplier *= ((at - pointJ.first)/(pointI.first - pointJ.first));
        }

        value += multiplier;
    }

    return value;
}

#ifndef LAGRANGEINTERPOLATION_H
#define LAGRANGEINTERPOLATION_H

#include "InterpolationFunction.h"

class LagrangeInterpolationFunction : public InterpolationFunction {
    public:
        LagrangeInterpolationFunction();
        LagrangeInterpolationFunction(const QVector<QPair<double, double> >& inPoints);
        LagrangeInterpolationFunction(const InterpolationFunction& copyThis);

        double interpolate(double at) const;
};

#endif // LAGRANGEINTERPOLATION_H

#ifndef LAGRANGEINTERPOLATION_H
#define LAGRANGEINTERPOLATION_H

#include "InterpolationFunction.h"

template <typename dataType = double>
class LagrangeInterpolationFunction : InterpolationFunction<dataType> {
    public:
        /*
        LagrangeInterpolationPolynomial();
        LagrangeInterpolationPolynomial(const std::vector<std::pair<double, double> >& inPoints);
        LagrangeInterpolationPolynomial(const LagrangeInterpolationPolynomial& copyThis);*/

        dataType interpolate(dataType at) const;
};

template <typename dataType>
dataType LagrangeInterpolationFunction<dataType>::interpolate(dataType at) const {
    dataType value = 0;

    for (int i = 0; i < InterpolationFunction<dataType>::getPointsCount(); i++) {
        std::vector<std::pair<dataType, dataType> > pointI = InterpolationFunction<dataType>::getPointAt(i);
        dataType multiplier = pointI->second;//y[i]

        for (int j = 0; j < InterpolationFunction<dataType>::getPointsCount(); j++) {
            if (i == j) {
                continue;
            }

            std::vector<std::pair<dataType, dataType> > pointJ = InterpolationFunction<dataType>::getPointAt(j);

            multiplier *= ((at - pointJ->first)/(pointI->first - pointJ->first));
        }

        value += multiplier;
    }

    return value;
}

#endif // LAGRANGEINTERPOLATION_H

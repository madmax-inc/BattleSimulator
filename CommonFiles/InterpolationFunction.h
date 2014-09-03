#ifndef INTERPOLATIONFUNCTION_H
#define INTERPOLATIONFUNCTION_H

#include <vector>

template <typename dataType = double>
class InterpolationFunction {
    private:
        std::vector<std::pair<dataType, dataType> > points;
    public:
        InterpolationFunction();
        InterpolationFunction(const std::vector<std::pair<dataType, dataType> >& inPoints);
        InterpolationFunction(const InterpolationFunction& copyThis);

        void addPoint(dataType argument, dataType value);
        void deletePoint(int index);
        void clearPoints();
        int getPointsCount() const;
        std::pair<dataType, dataType> getPointAt(int index) const;
        virtual dataType interpolate(dataType at) const = 0;
        dataType operator() (dataType at) const;
};

template <typename dataType>
InterpolationFunction<dataType>::InterpolationFunction()
{
}

template <typename dataType>
InterpolationFunction<dataType>::InterpolationFunction(const std::vector<std::pair<dataType, dataType> > &inPoints) : points(inPoints)
{
}

template <typename dataType>
InterpolationFunction<dataType>::InterpolationFunction(const InterpolationFunction<dataType> &copyThis) : points(copyThis.points)
{
}

template <typename dataType>
int InterpolationFunction<dataType>::getPointsCount() const
{
    return points.size();
}

template <typename dataType>
void InterpolationFunction<dataType>::addPoint(dataType argument, dataType value)
{
    points.push_back(std::pair<dataType, dataType>(argument, value));
}

template <typename dataType>
void InterpolationFunction<dataType>::clearPoints() {
    points.clear();
}

template <typename dataType>
void InterpolationFunction<dataType>::deletePoint(int index)
{
    points.erase(points.begin()+index);
}

template <typename dataType>
std::pair<dataType, dataType> InterpolationFunction<dataType>::getPointAt(int index) const
{
    return points[index];
}

template <typename dataType>
dataType InterpolationFunction<dataType>::operator()(dataType at) const
{
    return interpolate(at);
}


#endif // INTERPOLATIONFUNCTION_H

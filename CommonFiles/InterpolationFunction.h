#ifndef INTERPOLATIONFUNCTION_H
#define INTERPOLATIONFUNCTION_H

#include <QDataStream>
#include <QVector>
#include <QPair>

class InterpolationFunction {
    private:
        QVector<QPair<double, double> > points;
    public:
        InterpolationFunction();
        InterpolationFunction(const QVector<QPair<double, double> >& inPoints);
        InterpolationFunction(const InterpolationFunction& copyThis);

        void addPoint(double argument, double value);
        void addPoints(const QVector<QPair<double, double> >& inPoints);
        void deletePoint(int index);
        void clearPoints();
        int getPointsCount() const;
        QPair<double, double> getPointAt(int index) const;
        virtual double interpolate(double at) const = 0;
        double operator() (double at) const;

        //Serialization override
        friend QDataStream& operator<<(QDataStream& out, const InterpolationFunction& b);
        friend QDataStream& operator>>(QDataStream& in, InterpolationFunction& b);
};

#endif // INTERPOLATIONFUNCTION_H

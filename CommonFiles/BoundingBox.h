#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <QPair>
#include <QRectF>

class BoundingBox
{
    private:
        QPair<double, double> x;
        QPair<double, double> y;
        QPair<double, double> z;

    public:
        BoundingBox(const QPair<double, double>& xs, const QPair<double, double>& ys, const QPair<double, double>& zs);

        QRectF makeRect() const;
};

#endif // BOUNDINGBOX_H

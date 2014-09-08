#include "BoundingBox.h"

BoundingBox::BoundingBox(const QPair<double, double> &xs, const QPair<double, double> &ys, const QPair<double, double> &zs) : x(xs), y(ys), z(zs)
{
}

QRectF BoundingBox::makeRect() const
{
    return QRectF(QPointF(x.first, y.first), QPointF(x.second, y.second));
}

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDataStream>

class Vector3D {
    private:
        double x, y, z;

    public:
        Vector3D();
        Vector3D(double x, double y, double z);
        Vector3D(const Vector3D& copyThis);

        void normalize();

        double getLength() const;

        //Getters/setters
        double getX() const;
        void setX(double value);
        double getY() const;
        void setY(double value);
        double getZ() const;
        void setZ(double value);

        //Operators override
        Vector3D& operator=(const Vector3D& b);

        Vector3D& operator+=(const Vector3D& b);
        Vector3D& operator-=(const Vector3D& b);
        Vector3D& operator*=(double b);//Multiplication by scalar

        friend const Vector3D operator+(const Vector3D& a, const Vector3D& b);
        friend const Vector3D operator-(const Vector3D& a, const Vector3D& b);
        friend const double operator*(const Vector3D& a, const Vector3D& b);//Scalar multiplication
        //friend const Vector3D operator*(const Vector3D& a, const Vector3D& b);//Vector multiplication - Conflicts with scalar multiplication. Deprecated.
        friend const Vector3D operator*(const Vector3D& a, double b);//Multiplication by scalar

        friend QDataStream& operator<<(QDataStream& out, const Vector3D& b);
        friend QDataStream& operator>>(QDataStream& in, Vector3D& b);

        //Static functions
        static double getDistanceBetween(const Vector3D& a, const Vector3D& b);//Distance between 2 points
        static double getAngleBetween(const Vector3D& a, const Vector3D& b);
};

#endif // GEOMETRY_H

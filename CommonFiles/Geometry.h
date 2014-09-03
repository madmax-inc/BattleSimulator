#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDataStream>

template <typename dataType = double>
class Vector3D {
    private:
        dataType x, y, z;

    public:
        Vector3D();
        Vector3D(dataType x, dataType y, dataType z);
        Vector3D(const Vector3D<dataType>& copyThis);

        void normalize();

        double getLength() const;

        //Getters/setters
        dataType getX() const;
        void setX(dataType value);
        dataType getY() const;
        void setY(dataType value);
        dataType getZ() const;
        void setZ(dataType value);

        //Operators override
        Vector3D<dataType>& operator=(const Vector3D<dataType>& b);

        Vector3D<dataType>& operator+=(const Vector3D<dataType>& b);
        Vector3D<dataType>& operator-=(const Vector3D<dataType>& b);
        Vector3D<dataType>& operator*=(double b);//Multiplication by scalar

        friend const Vector3D<dataType> operator+(const Vector3D<dataType>& a, const Vector3D<dataType>& b);
        friend const Vector3D<dataType> operator-(const Vector3D<dataType>& a, const Vector3D<dataType>& b);
        friend const double operator*(const Vector3D<dataType>& a, const Vector3D<dataType>& b);//Scalar multiplication
        //friend const Vector3D<dataType> operator*(const Vector3D<dataType>& a, const Vector3D<dataType>& b);//Vector multiplication - Conflicts with scalar multiplication. Deprecated.
        friend const Vector3D<dataType> operator*(const Vector3D<dataType>& a, double b);//Multiplication by scalar

        friend QDataStream& operator<<(QDataStream& out, const Vector3D& b);
        friend QDataStream& operator>>(QDataStream& in, Vector3D& b);

        //Static functions
        static double getDistanceBetween(const Vector3D<dataType>& a, const Vector3D<dataType>& b);//Distance between 2 points
        static double getAngleBetween(const Vector3D<dataType>& a, const Vector3D<dataType>& b);
};

#endif // GEOMETRY_H

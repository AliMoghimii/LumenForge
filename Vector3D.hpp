#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>
#include <iostream>
using namespace std;


class Vector3D 
{
    public: 

        double x;
        double y;
        double z;
        
    Vector3D(double x, double y, double z);

    void printVector() const;

    double magnitude() const;

    Vector3D normalize() const;

    double dot(Vector3D other) const;

    Vector3D operator+(Vector3D other) const;

    Vector3D operator-(Vector3D other) const;

    Vector3D operator*(double number) const;

    friend Vector3D operator*(double number, const Vector3D& vector);

    Vector3D operator/(double number) const;
};

#endif
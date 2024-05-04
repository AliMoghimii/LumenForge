#ifndef OBJECT3DSPHERE_H
#define OBJECT3DSPHERE_H

#include "Object3D.hpp"

#include <math.h>
#include <iostream>
using namespace std;

class Object3DSphere : public Object3D
{
    public: 

        double radius;

    Object3DSphere();    

    Object3DSphere(Vector3D center, double radius, Material* material);

    double object3DIntersects(const Ray& ray) const;

    Vector3D object3DNormal(Vector3D surfacePoint);
};

#endif
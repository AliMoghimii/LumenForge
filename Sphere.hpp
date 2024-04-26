#ifndef SPHERE_H
#define SPHERE_H

#include "Object3D.hpp"

#include <math.h>
#include <iostream>
using namespace std;

class Sphere : public Object3D
{
    public: 

        Vector3D center;
        double radius;

    Sphere();    

    Sphere(Vector3D center, double radius, Color material);

    double Object3DIntersects(const Ray& ray) const;
};

#endif
#ifndef Object3D_H
#define Object3D_H

#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Color.hpp"

#include <math.h>
#include <iostream>
using namespace std;

class Object3D 
{
    public:

        string name;
        Color material;

    Object3D();

    virtual double Object3DIntersects(const Ray& ray) const;
};

#endif
#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Material.hpp"

#include <math.h>
#include <iostream>
using namespace std;

class Object3D 
{
    public:

        Vector3D center;
        Material* material;
        
    Object3D();

    virtual double object3DIntersects(const Ray& ray) const;
    
    virtual Vector3D object3DNormal(Vector3D surfacePoint);
};

#endif
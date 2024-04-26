#ifndef ENGINE_H
#define ENGINE_H

#include "Image.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"
#include "Scene.hpp"
#include "Object3D.hpp" 

#include <math.h>
#include <float.h>
#include <iostream>
using namespace std;

class Engine 
{
    public: 

    Image render(const Scene& scene);

    Color raytrace(const Ray& ray, const Scene& scene);

    pair<Object3D*, float> getRayHit(const Ray& ray, const Scene& scene);

    Color colorAccumulation(Object3D* Object3DHit, const Vector3D& hitPosition, const Scene& scene);
    
};

#endif
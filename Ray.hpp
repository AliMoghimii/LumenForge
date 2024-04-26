#ifndef RAY_H
#define RAY_H

#include "Vector3D.hpp"

#include <math.h>
#include <iostream>
using namespace std;

class Ray 
{
    public: 

        Vector3D origin;
        Vector3D direction;

    Ray(Vector3D origin, Vector3D direction);
};

#endif
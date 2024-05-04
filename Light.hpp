#ifndef LIGHT_H
#define LIGHT_H

#include "Vector3D.hpp"
#include "Color.hpp"

#include <math.h>
#include <iostream>
using namespace std;

class Light
{
    public: 

        Vector3D position;
        Color color;

    Light(Vector3D position, Color color);
};

#endif
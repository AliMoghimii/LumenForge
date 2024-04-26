#ifndef SCENE_H
#define SCENE_H

#include "Vector3D.hpp"
#include "Object3D.hpp"

#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

class Scene 
{
    public: 

        Vector3D camera;
        vector<Object3D*> Object3Ds;
        int width;
        int height;

    Scene(Vector3D camera, vector<Object3D*> Object3Ds, int width, int height);
};

#endif
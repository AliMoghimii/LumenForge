#ifndef SCENE_H
#define SCENE_H

#include "Vector3D.hpp"
#include "Object3D.hpp"
#include "Light.hpp"

#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

class Scene 
{
    public: 

        Vector3D camera;
        vector<Object3D*> objects;
        vector<Light*> lights;
        int width;
        int height;

    Scene(Vector3D camera, vector<Object3D*> objects, vector<Light*> lights, int width = 0, int height = 0);
};

#endif
#include "Scene.hpp"

Scene::Scene(Vector3D camera, vector<Object3D*> Object3Ds, int width, int height)
{
    this->camera = camera;
    this->Object3Ds = Object3Ds;
    this->width = width;
    this->height = height;
}
#include "Scene.hpp"

Scene::Scene(Vector3D camera, vector<Object3D*> objects, vector<Light*> lights, int width, int height)
{
    this->camera = camera;
    this->objects = objects;
    this->lights = lights;
    this->width = width;
    this->height = height;
}
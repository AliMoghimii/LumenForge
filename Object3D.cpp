#include "Object3D.hpp"

Object3D::Object3D()
{

}

double Object3D::object3DIntersects(const Ray& ray) const
{
    return 0.0;
}

Vector3D Object3D::object3DNormal(Vector3D surfacePoint)
{
    return Vector3D(0, 0, 0);
}


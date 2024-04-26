#include "Ray.hpp"

Ray::Ray(Vector3D origin, Vector3D direction)
{
    this->origin = origin;
    this->direction = direction.normalize();
}
#include "Ray.hpp"

Ray::Ray(Vector3D origin, Vector3D direction, bool normalize)
{
    this->origin = origin;
    
    if(normalize)
        this->direction = direction.normalize();
    else
        this->direction = direction;
}
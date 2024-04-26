#include "Sphere.hpp"

Sphere::Sphere()
{

}

Sphere::Sphere(Vector3D center, double radius, Color material)
{
    this->name = "Sphere";
    this->center = center;
    this->radius = radius;
    this->material = material;
}

double Sphere::Object3DIntersects(const Ray& ray) const
{
    Vector3D rayDirection = ray.origin - center;

    double a = 1.0;
    double b = 2.0 * ray.direction.dot(rayDirection);
    double c = rayDirection.dot(rayDirection) - radius * radius;

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant >= 0) 
    {
        double dist = (-b + sqrt(discriminant)) / (2.0 * a);
        if (dist > 0) 
        {
            return dist;
        }
    }
    return -1.0;
}

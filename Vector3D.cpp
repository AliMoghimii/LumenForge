#include "Vector3D.hpp"

Vector3D::Vector3D(double x, double y, double z) //: x(x), y(y), z(z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3D::printVector() const
{
    cout << '[' << x << ',' << y << ',' << z << ']' << endl;
}

double Vector3D::magnitude() const
{
    //return sqrt(pow(x,2) + pow(y,2) + pow(z,2)); 
    return sqrt(this->dot(*this)); 
}

Vector3D Vector3D::normalize() const
{
    return *this / this->magnitude();
}

double Vector3D::dot(Vector3D other) const
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3D Vector3D::operator+(Vector3D other) const
{
    return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3D Vector3D::operator-(Vector3D other) const
{
    return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3D Vector3D::operator*(double number) const
{
    return Vector3D(this->x * number, this->y * number, this->z * number);
}

Vector3D operator*(double number, const Vector3D& vector)
{
    return vector * number;
}

Vector3D Vector3D::operator/(double number) const
{
    return Vector3D(this->x / number, this->y / number, this->z / number);
}

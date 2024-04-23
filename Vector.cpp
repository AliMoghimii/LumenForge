#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
    public: 

        double X;
        double Y;
        double Z;

        Vector(double X = 0, double Y = 0, double Z = 0)
        {
            this->X = X;
            this->Y = Y;
            this->Z = Z;
        }

        //Vector(double x, double y, double z) : X(x), Y(y), Z(z) {}

        void printVector() const
        {
            cout << '[' << X << ',' << Y << ',' << Z << ']' << endl;
        }

        double magnitude() const
        {
            //return sqrt(pow(X,2) + pow(Y,2) + pow(Z,2)); 
            return sqrt(this->dot(*this)); 
        }

        Vector normalize() const
        {
            return *this / this->magnitude();
        }

        double dot(Vector other) const
        {
            return this->X * other.X + this->Y * other.Y + this->Z * other.Z;
        }

        Vector operator+(Vector other) const
        {
            return Vector(this->X + other.X, this->Y + other.Y, this->Z + other.Z);
        }

        Vector operator-(Vector other) const
        {
            return Vector(this->X - other.X, this->Y - other.Y, this->Z - other.Z);
        }

        Vector operator*(double number) const
        {
            return Vector(this->X * number, this->Y * number, this->Z * number);
        }

        friend Vector operator*(double number, const Vector& vector)
        {
            return vector * number;
        }

        Vector operator/(double number) const
        {
            return Vector(this->X / number, this->Y / number, this->Z / number);
        }
};
#include "Color.hpp"

Color::Color(double r, double g, double b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Color Color::operator+(Color other) const
{
    return Color(this->r + other.r, this->g + other.g, this->b + other.b);
}

Color Color::operator-(Color other) const
{
    return Color(this->r - other.r, this->g - other.g, this->b - other.b);
}

Color Color::operator*(double number) const
{
    return Color(this->r * number, this->g * number, this->b * number);
}

Color operator*(double number, const Color& vector)
{
    return vector * number;
}

Color Color::operator/(double number) const
{
    return Color(this->r / number, this->g / number, this->b / number);
}
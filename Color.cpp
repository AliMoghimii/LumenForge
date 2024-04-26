#include "Color.hpp"

Color::Color(double r, double g, double b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void Color::printColor() const
{
    cout << '[' << r << ',' << g << ',' << b << ']' << endl;
}

Color Color::HexToRgb(const string& hexValue)
{
    double r = stoi(hexValue.substr(1, 2), nullptr, 16) / 255.0;
    double g = stoi(hexValue.substr(3, 2), nullptr, 16) / 255.0;
    double b = stoi(hexValue.substr(5, 2), nullptr, 16) / 255.0;
    return Color(r, g, b);
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
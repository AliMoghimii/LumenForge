#ifndef COLOR_H
#define COLOR_H

#include <math.h>
#include <iostream>
using namespace std;

class Color 
{
    public: 

        double r;
        double g;
        double b;
        
    Color(double r = 0, double g = 0, double b = 0);

    void printColor() const;

    Color operator+(Color other) const;

    Color operator-(Color other) const;

    Color operator*(double number) const;

    friend Color operator*(double number, const Color& vector);

    Color operator/(double number) const;
};

#endif
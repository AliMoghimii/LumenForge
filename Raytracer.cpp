#include "Image.hpp"
#include "Color.hpp"

#include <iostream>
using namespace std;

double width = 3;
double height = 3;

int main ()
{
    Image image =  Image(width, height);

    Color colorRed = Color(1, 0, 0);
    Color colorGreen = Color(0, 1, 0);
    Color colorBlue = Color(0, 0, 1);
    
    image.setPixel(0, 0, colorRed);
    image.setPixel(1, 0, colorGreen);
    image.setPixel(2, 0, colorBlue);

    image.setPixel(0, 1, colorRed + colorGreen);
    image.setPixel(1, 1, colorBlue + colorGreen);
    image.setPixel(2, 1, colorBlue + colorRed);

    image.setPixel(0, 2, colorRed + colorGreen + colorBlue);
    image.setPixel(1, 2, colorRed + Color(0, 0.5, 0));
    image.setPixel(2, 2, colorRed * 0.001);

    image.exportImage("test.ppm");

    cout << " " << endl;

    return 0;
}

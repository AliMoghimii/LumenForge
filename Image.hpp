#ifndef IMAGE_H
#define IMAGE_H

#include "Color.hpp"

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Image 
{
    public: 

        int w;
        int h;
        vector<vector<Color>> pixels;

    Image(int w = 0, int h = 0);

    void createImageCanvas();

    int toByte(double character);

    void exportImage(const string& filename);

    void setPixel(int x, int y, Color color);
};

#endif
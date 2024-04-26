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

        int width;
        int height;
        vector<vector<Color>> pixels;

    Image(int width = 0, int height = 0);

    void createImageCanvas();

    int toByte(double character);

    void exportImage(const string& filename);

    void setPixel(int x, int y, Color color);
};

#endif
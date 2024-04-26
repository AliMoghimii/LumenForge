#include "Image.hpp"

Image::Image(int width, int height) : width(width), height(height) 
{ 
    this->width = width;
    this->height = height;
    createImageCanvas();
}

void Image::createImageCanvas()
{
    pixels.resize(height);
    for (int i = 0; i < height; ++i) 
    {
        pixels[i].resize(width);
    }
}

int Image::toByte(double character) 
{
    return round(max(min(character * 255.0, 255.0), 0.0));
}

void Image::setPixel(int x, int y, Color color)
{
    if (y >= 0 && y < pixels.size() && x >= 0 && x < pixels[y].size()) 
    {
        //cout << "Pixel added at (" << x << ", " << y << ")" << endl;
        pixels[y][x] = color;
    } 
    else 
    {
        cout << "Invalid pixel coordinates (" << x << ", " << y << ")" << endl;
    }
}

void Image::exportImage(const string& filename) 
{
        ofstream file(filename);

        if (!file.is_open()) 
        {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        file << "P3 " << width << " " << height << "\n255\n";

        for (auto row : pixels) 
        {
            for (auto color : row) 
            {
                file << toByte(color.r) << " " << toByte(color.g) << " " << toByte(color.b) << " ";
            }
            file << "\n";
        }

        file.close();
    }

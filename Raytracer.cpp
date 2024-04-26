#include "Color.hpp"
#include "Vector3D.hpp"
#include "Sphere.hpp"
#include "Object3D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"

#include <vector>
#include <iostream>
using namespace std;

double width = 640;
double height = 640;

int main ()
{
    Vector3D camera = Vector3D(0, 0, -1);

    Color color;
    
    vector<Object3D*> Object3Ds;
    Object3Ds.push_back(new Sphere(Vector3D(-0.5, -0.5, 0), 0.25, color.HexToRgb("#FF0000")));
    Object3Ds.push_back(new Sphere(Vector3D(0, -0.5, 0), 0.25, color.HexToRgb("#00FF00")));
    Object3Ds.push_back(new Sphere(Vector3D(0.5, -0.5, 0), 0.25, color.HexToRgb("#0000FF")));
    Object3Ds.push_back(new Sphere(Vector3D(-0.5, 0, 0), 0.25, color.HexToRgb("#FFFF00+")));
    Object3Ds.push_back(new Sphere(Vector3D(0, 0, 0), 0.25, color.HexToRgb("#00FFFF")));
    Object3Ds.push_back(new Sphere(Vector3D(0.5, 0, 0), 0.25, color.HexToRgb("#FF00FF")));
    Object3Ds.push_back(new Sphere(Vector3D(-0.5, 0.5, 0), 0.25, color.HexToRgb("#FFFFFF")));
    Object3Ds.push_back(new Sphere(Vector3D(0, 0.5, 0), 0.25, color.HexToRgb("#FF8000")));
    Object3Ds.push_back(new Sphere(Vector3D(0.5, 0.5, 0), 0.25, color.HexToRgb("#404040")));

    Scene scene = Scene(camera, Object3Ds, width, height) ;

    Engine engine = Engine();

    Image image =  engine.render(scene);

    image.exportImage("01 - Render Test.ppm");

    for (Object3D* obj : Object3Ds)
    {
        delete obj;
    }

    return 0;
}

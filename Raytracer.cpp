#include "Color.hpp"
#include "Vector3D.hpp"
#include "Object3DSphere.hpp"
#include "Object3D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "Light.hpp"
#include "MaterialNormal.hpp"
#include "MaterialCheckered.hpp"

#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;

double width = 1280;
double height = 720;

int main ()
{
    system("cls");

    Color color;

    Vector3D camera = Vector3D(0, 0, -1);
    
    vector<Object3D*> objects;
    objects.push_back(new Object3DSphere(Vector3D(0, 3.45, 1), 3, new MaterialNormal(color.HexToRgb("#111111"), 0.05, 1, 1, 0.25)));
    objects.push_back(new Object3DSphere(Vector3D(0, 0, 1), 0.5, new MaterialNormal(color.HexToRgb("#FF0000"), 0.05, 1, 1, 0.35)));
    objects.push_back(new Object3DSphere(Vector3D(0.75, 0.05, 1.35), 0.5, new MaterialNormal(color.HexToRgb("#FFFF00"), 0.05, 1, 1, 0.45)));
    objects.push_back(new Object3DSphere(Vector3D(-0.75, 0.05, 1.35), 0.5, new MaterialCheckered(color.HexToRgb("#0000FF"), color.HexToRgb("#FFFFFF"), 0.05, 1, 1, 0.75)));

    vector<Light*> lights;
    lights.push_back(new Light(Vector3D(25, -50, 50), color.HexToRgb("#FFFFFF")));

    Scene scene = Scene(camera, objects, lights, width, height);

    Engine engine = Engine();

    Image image =  engine.render(scene);

    image.exportImage("03 - Reflection Test.ppm");

    for (Object3D* obj : objects)
    {
        delete obj;
    }

    return 0;
}

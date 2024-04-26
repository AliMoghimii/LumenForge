#include "Engine.hpp"

Image Engine::render(const Scene& scene)
{
    int width = scene.width;
    int height = scene.height;
    double aspectRatio = static_cast<double>(width) / height;
    double x0 = -1.0;
    double x1 = 1.0;
    double xdelta = (x1 - x0) / (width - 1);

    double y0 = -1.0 / aspectRatio;
    double y1 = 1.0 / aspectRatio;
    double ydelta = (y1 - y0) / (height - 1);

    Vector3D camera = scene.camera;
    Image canvas = Image(width, height);

    for (int j = 0; j < height; ++j) 
    {
        float y = y0 + j * ydelta;

        for (int i = 0; i < width; ++i) 
        {
            float x = x0 + i * xdelta;
            Ray ray = Ray(camera, Vector3D(x, y, 0) - camera);
            canvas.setPixel(i, j, raytrace(ray, scene));
        }
        double progress = (double)(j) / height * 100;
        cout << "Rendering: In Progress (" << (int) progress << "%)";
        cout.flush();
        cout << "\r";
    }
    cout << "Rendering: Completed Successfully (100%)" << endl;
    return canvas;
}

Color Engine::raytrace(const Ray& ray, const Scene& scene)
{
    Color color = Color(0, 0, 0);

    double distanceHit;
    Object3D* Object3DHit;

    tie(Object3DHit, distanceHit) = getRayHit(ray, scene);
    
    if (Object3DHit == nullptr) 
        return color;

    Vector3D hitPos = ray.origin + ray.direction * distanceHit;
    color = color + colorAccumulation(Object3DHit, hitPos, scene);
    return color;
}

pair<Object3D*, float> Engine::getRayHit(const Ray& ray, const Scene& scene)
{
    double distanceMin = DBL_MAX;
    Object3D* Object3DHit = nullptr;

    for (Object3D* obj : scene.Object3Ds) 
    {
        float distance = obj->Object3DIntersects(ray);
        if ((distance != -1) && (Object3DHit == nullptr || distance < distanceMin)) 
        {
            distanceMin = distance;
            Object3DHit = obj;
        }
    }

    return make_pair(Object3DHit, distanceMin);
}

Color Engine::colorAccumulation(Object3D* Object3DHit, const Vector3D& hitPosition, const Scene& scene) 
{
    return Object3DHit->material;
}
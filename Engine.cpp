#include "Engine.hpp"

Image Engine::render(const Scene& scene, bool shaded)
{
    this->shaded = shaded;

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
            Ray ray = Ray(camera, Vector3D(x, y) - camera);
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

Color Engine::raytrace(const Ray& ray, const Scene& scene, int depth)
{
    Color color = Color(0, 0, 0);

    double distanceHit;
    Object3D* objectHit;

    tie(objectHit, distanceHit) = rayCollision(ray, scene);
    
    if(objectHit == nullptr) 
        return color;

    Vector3D hitPosition = ray.origin + ray.direction * distanceHit;
    Vector3D hitNormal = objectHit->object3DNormal(hitPosition);

    color = color + colorBlending(objectHit, hitPosition, hitNormal, scene);

    if(depth < this->maxDepth)
    {
        Vector3D newRayOrigin = hitPosition + hitNormal * this->minDisplacement;
        Vector3D newRayDirection = ray.direction - 2 * ray.direction.dot(hitNormal) * hitNormal;
        Ray reflectedRay = Ray(newRayOrigin, newRayDirection, false);
        color = color + raytrace(reflectedRay, scene, depth + 1) * objectHit->material->reflection;
    }

    return color;
}

pair<Object3D*, float> Engine::rayCollision(const Ray& ray, const Scene& scene)
{
    double distanceMin = DBL_MAX;
    Object3D* objectHit = nullptr;

    for (Object3D* object : scene.objects) 
    {
        float distance = object->object3DIntersects(ray);
        if((distance != -1) && (objectHit == nullptr || distance < distanceMin)) 
        {
            distanceMin = distance;
            objectHit = object;
        }
    }

    return make_pair(objectHit, distanceMin);
}

Color Engine::colorBlending(Object3D* objectHit, const Vector3D& hitPosition, const Vector3D& hitNormal, const Scene& scene) 
{
    if(!this->shaded)
        return objectHit->material->colorA;

    Material* objectHitMaterial = objectHit->material;
    Color objectHitColor = objectHitMaterial->colorBlendingProperties(hitPosition); 
    Ray rayToCamera = Ray(hitPosition, scene.camera - hitPosition, false);
    Color newColor = objectHitMaterial->ambient * newColor.HexToRgb("#FFFFFF");

    double shadowDetectDistanceHit;
    Object3D* shadowDetectObjectHit;
    
    for (Light* light : scene.lights)
    {
        Ray rayToLight = Ray(hitPosition, light->position - hitPosition);
        // tie(shadowDetectObjectHit, shadowDetectDistanceHit) = rayCollision(rayToLight, scene);
        // if(shadowDetectObjectHit == nullptr || shadowDetectDistanceHit > (light->position - hitPosition).magnitude()) 
        newColor = newColor + lambertianShading(objectHitMaterial, objectHitColor, hitNormal, rayToLight);
        newColor = newColor + blingPhongShading(objectHitMaterial, *light, hitNormal, rayToLight, rayToCamera, 50);
    }

    return newColor;
}

Color Engine::lambertianShading(const Material* objectHitMaterial, const Color& objectHitColor, const Vector3D& hitNormal, const Ray& rayToLight) 
{
    return objectHitColor * objectHitMaterial->diffuse * max(hitNormal.dot(rayToLight.direction), 0.0);
}

Color Engine::blingPhongShading(const Material* objectHitMaterial, const Light& light, const Vector3D& hitNormal, const Ray& rayToLight, const Ray& rayToCamera, double specularExponent) 
{
    Vector3D halfVector = (rayToLight.direction + rayToCamera.direction).normalize();
    return light.color * objectHitMaterial->specular * pow(max(hitNormal.dot(halfVector), 0.0),  specularExponent);
}
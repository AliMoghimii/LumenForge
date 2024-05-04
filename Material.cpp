#include "Material.hpp"

Material::Material()
{

}

Color Material::colorBlendingProperties(const Vector3D& hitPosition) const
{
    return Color(1,1,1);
}

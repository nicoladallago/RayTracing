#include "LambertianSphere.h"

API const Lambertian* LambertianSphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   return (BaseSphere::HitBase(ray, rayT, rec) ? &m_material : nullptr);
}
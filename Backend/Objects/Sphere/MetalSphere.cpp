#include "MetalSphere.h"

API const Metal* MetalSphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   return (BaseSphere::HitBase(ray, rayT, rec) ? &m_material : nullptr);
}
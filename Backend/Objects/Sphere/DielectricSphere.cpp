#include "DielectricSphere.h"

API DielectricSphere::DielectricSphere(const Point3& center, const double radius, const double indexOfRefraction) noexcept:
    BaseSphere(center, radius),
    m_material(indexOfRefraction) {
}


API const Dielectric* DielectricSphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   return (BaseSphere::HitBase(ray, rayT, rec) ? &m_material : nullptr);
}
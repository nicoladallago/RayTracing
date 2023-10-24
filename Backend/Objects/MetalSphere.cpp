#include "MetalSphere.h"

API MetalSphere::MetalSphere(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) noexcept:
    BaseSphere(center, radius),
    m_material(albedo, fuzz) {
}


API const Metal* MetalSphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   return (BaseSphere::HitBase(ray, rayT, rec) ? &m_material : nullptr);
}
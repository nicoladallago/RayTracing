#include "LambertianSphere.h"

API LambertianSphere::LambertianSphere(const Point3& center, const double radius, const Pixel& albedo) noexcept:
    BaseSphere(center, radius),
    m_material(albedo) {
}


API const Lambertian* LambertianSphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   return (BaseSphere::HitBase(ray, rayT, rec) ? &m_material : nullptr);
}
#include "Metal.h"

API constexpr Metal::Metal(const Image::Pixel& a) noexcept:
    m_albedo(a) {
}


API constexpr bool Metal::Scatter(const Ray& ray,
                                  const Hittable::HitRecord& rec,
                                  Image::Pixel& attenuation,
                                  Ray& scattered) const noexcept {
   Vector3d reflected = Reflect(UnitVector(ray.GetDirection()), rec.normal);
   scattered = Ray(rec.p, reflected);
   attenuation = m_albedo;
   return true;
}
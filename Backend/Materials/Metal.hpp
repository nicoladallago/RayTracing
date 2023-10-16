#include "Metal.h"

API constexpr Metal::Metal(const Image::Pixel& a, const double f) noexcept:
    m_albedo(a),
    m_fuzz(f) {
}


API bool Metal::Scatter(const Ray& ray,
                        const Hittable::HitRecord& rec,
                        Image::Pixel& attenuation,
                        Ray& scattered) const noexcept {
   const Vector3d reflected = Reflect(UnitVector(ray.GetDirection()), rec.normal);
   scattered = Ray(rec.p, reflected + m_fuzz * RandomUnitVector<double>());
   attenuation = m_albedo;
   return (Dot(scattered.GetDirection(), rec.normal) > 0);
}
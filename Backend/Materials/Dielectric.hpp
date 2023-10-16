#include "Dielectric.h"
#include "Image/Image.h"

API constexpr Dielectric::Dielectric(const double indexOfRefraction) noexcept:
    m_ir(indexOfRefraction) {
}


API constexpr bool Dielectric::Scatter(const Ray& ray,
                                       const Hittable::HitRecord& rec,
                                       Image::Pixel& attenuation,
                                       Ray& scattered) const noexcept {
   attenuation = Image::Pixel(1, 1, 1);
   const double refractionRatio = rec.frontFace ? (1.0 / m_ir) : m_ir;

   const Vector3d unitDirection = UnitVector(ray.GetDirection());
   const Vector3d refracted = Refract<double>(unitDirection, rec.normal, refractionRatio);

   scattered = Ray(rec.p, refracted);
   return true;
}
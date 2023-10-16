#include "Dielectric.h"
#include "Image/Image.h"

API constexpr Dielectric::Dielectric(const double indexOfRefraction) noexcept:
    m_ir(indexOfRefraction) {
}


API bool Dielectric::Scatter(const Ray& ray,
                             const Hittable::HitRecord& rec,
                             Image::Pixel& attenuation,
                             Ray& scattered) const noexcept {
   attenuation = Image::Pixel(1, 1, 1);
   const double refractionRatio = rec.frontFace ? (1.0 / m_ir) : m_ir;

   const Vector3d unitDirection = UnitVector(ray.GetDirection());
   const double cosTheta = std::fmin(Dot(-unitDirection, rec.normal), 1.0);
   const double sinTheta = std::sqrt(1 - cosTheta * cosTheta);

   const bool cannotRefract = refractionRatio * sinTheta > 1;
   Vector3d direction;

   if(cannotRefract) {
      direction = Reflect<double>(unitDirection, rec.normal);
   }
   else {
      direction = Refract<double>(unitDirection, rec.normal, refractionRatio);
   }

   scattered = Ray(rec.p, direction);
   return true;
}
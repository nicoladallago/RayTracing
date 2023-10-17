#include "Dielectric.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"

API bool Dielectric::Scatter(const Ray& ray,
                             const HitRecord& rec,
                             Pixel& attenuation,
                             Ray& scattered) const noexcept {
   attenuation = Pixel(1, 1, 1);
   const double refractionRatio = rec.frontFace ? (1.0 / m_ir) : m_ir;

   const Vector3d unitDirection = UnitVector(ray.GetDirection());
   const double cosTheta = std::fmin(Dot(-unitDirection, rec.normal), 1.0);
   const double sinTheta = std::sqrt(1 - cosTheta * cosTheta);

   const bool cannotRefract = refractionRatio * sinTheta > 1;
   Vector3d direction;

   if(cannotRefract || Reflectance(cosTheta, refractionRatio) > Utils::Random()) {
      direction = Reflect<double>(unitDirection, rec.normal);
   }
   else {
      direction = Refract<double>(unitDirection, rec.normal, refractionRatio);
   }

   scattered = Ray(rec.p, direction);
   return true;
}


double Dielectric::Reflectance(const double cosine, const double refIdx) noexcept {
   // Use Schlick's approximation for reflectance.
   double r0 = (1 - refIdx) / (1 + refIdx);
   r0 = r0 * r0;
   return r0 + (1 - r0) * std::pow((1 - cosine), 5);
}
#include "Dielectric.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"

API bool Dielectric::Scatter(const Ray& ray,
                             const HitRecord& rec,
                             Pixel& attenuation,
                             Ray& scattered) const noexcept {
   attenuation = ATTENUATION;
   const double refractionRatio = rec.IsFrontFace() ? m_inverseIr : m_ir;

   const Vector3 unitDirection = UnitVector(ray.GetDirection());
   const double cosTheta = std::min(Dot(-unitDirection, rec.GetNormal()), 1.0);
   const double sinTheta = Utils::Sqrt(1 - cosTheta * cosTheta);

   const bool cannotRefract = refractionRatio * sinTheta > 1;
   Vector3 direction;

   if(cannotRefract || Reflectance(cosTheta, refractionRatio) > Utils::Random()) {
      direction = Reflect(unitDirection, rec.GetNormal());
   }
   else {
      direction = Refract(unitDirection, rec.GetNormal(), refractionRatio);
   }

   scattered = Ray(rec.GetPoint(), direction);
   return true;
}
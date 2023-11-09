#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP
#pragma once
#include "Dielectric.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"

constexpr Dielectric::Dielectric(const double indexOfRefraction) noexcept:
    m_ir(indexOfRefraction),
    m_inverseIr(1 / indexOfRefraction) {
}


inline bool Dielectric::Scatter(const Ray& ray,
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


constexpr double Dielectric::Reflectance(const double cosine, const double refIdx) noexcept {
   // Use Schlick's approximation for reflectance.
   double r0 = (1 - refIdx) / (1 + refIdx);
   r0 = r0 * r0;
   return r0 + (1 - r0) * Utils::Pow((1 - cosine), REFLECTANCE_EXPONENT);
}

#endif
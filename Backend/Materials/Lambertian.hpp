#ifndef LAMBERTIAN_HPP
#define LAMBERTIAN_HPP
#pragma once
#include "Lambertian.h"
#include "Objects/HitRecord.h"

constexpr Lambertian::Lambertian(const Pixel& a) noexcept:
    m_albedo(a) {
}


API inline bool Lambertian::Scatter([[maybe_unused]] const Ray& ray,
                                    const HitRecord& rec,
                                    Pixel& attenuation,
                                    Ray& scattered) const noexcept {
   Vector3 scatterDirection = rec.GetNormal() + RandomUnitVector();

   // Catch degenerate scatter direction
   if(scatterDirection.NearZero()) {
      scatterDirection = rec.GetNormal();
   }

   scattered = Ray(rec.GetPoint(), scatterDirection);
   attenuation = m_albedo;
   return true;
}

#endif
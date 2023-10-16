#ifndef LAMBERTIAN_HPP
#define LAMBERTIAN_HPP
#pragma once
#include "Lambertian.h"

API constexpr Lambertian::Lambertian(const Image::Pixel& a) noexcept:
    m_albedo(a) {
}


API bool Lambertian::Scatter([[maybe_unused]] const Ray& ray,
                             const HitRecord& rec,
                             Image::Pixel& attenuation,
                             Ray& scattered) const noexcept {
   Vector3d scatterDirection = rec.normal + RandomUnitVector<double>();

   // Catch degenerate scatter direction
   if(scatterDirection.NearZero()) {
      scatterDirection = rec.normal;
   }

   scattered = Ray(rec.p, scatterDirection);
   attenuation = m_albedo;
   return true;
}

#endif
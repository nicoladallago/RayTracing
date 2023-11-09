#ifndef DIELECTRIC_H
#define DIELECTRIC_H
#pragma once
#include "Geometry/Point3.h"
#include "Materials/Material.h"

class Dielectric: public Material {
 private:
   static constexpr int REFLECTANCE_EXPONENT = 5;
   static constexpr Pixel ATTENUATION = Pixel(1, 1, 1);

   const double m_ir; // index of refraction
   const double m_inverseIr;

 public:
   constexpr Dielectric(const double indexOfRefraction) noexcept;

   [[nodiscard]] virtual inline bool Scatter(const Ray& ray,
                                             const HitRecord& rec,
                                             Pixel& attenuation,
                                             Ray& scattered) const noexcept override final;

 private:
   static constexpr double Reflectance(const double cosine, const double refIdx) noexcept;
};

#include "Dielectric.hpp"
#endif
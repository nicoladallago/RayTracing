#ifndef DIELECTRIC_H
#define DIELECTRIC_H
#pragma once
#include "Materials/Material.h"

class Dielectric: public Material {
 private:
   const double m_ir; // index of refraction

 public:
   API constexpr Dielectric(const double indexOfRefraction) noexcept;

   [[nodiscard]] API virtual bool Scatter(const Ray& ray,
                                          const HitRecord& rec,
                                          Pixel& attenuation,
                                          Ray& scattered) const noexcept override final;

 private:
   static double Reflectance(const double cosine, const double refIdx) noexcept;
};

#include "Dielectric.hpp"
#endif
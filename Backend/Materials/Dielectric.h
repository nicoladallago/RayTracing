#ifndef DIELECTRIC_H
#define DIELECTRIC_H
#pragma once
#include "Materials/Material.h"

class Dielectric: public Material {
 private:
   const double m_ir; // index of refraction

 public:
   API constexpr Dielectric(const double indexOfRefraction) noexcept;

   [[nodiscard]] API virtual constexpr bool Scatter(const Ray& ray,
                                                    const Hittable::HitRecord& rec,
                                                    Image::Pixel& attenuation,
                                                    Ray& scattered) const noexcept override final;
};

#include "Dielectric.hpp"
#endif
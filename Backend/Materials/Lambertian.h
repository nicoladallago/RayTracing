#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H
#pragma once
#include "Materials/Material.h"
#include "Geometry/Point3.h"

class Lambertian: public Material {
 private:
   const Pixel m_albedo;

 public:
   constexpr Lambertian(const Pixel& a) noexcept;

   [[nodiscard]] virtual inline bool Scatter(const Ray& ray,
                                             const HitRecord& rec,
                                             Pixel& attenuation,
                                             Ray& scattered) const noexcept override final;
};

#include "Lambertian.hpp"
#endif
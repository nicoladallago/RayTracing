#ifndef METAL_H
#define METAL_H
#pragma once
#include "Geometry/Point3.h"
#include "Materials/Material.h"

class Metal: public Material {
 private:
   const Pixel m_albedo;
   const double m_fuzz;

 public:
   constexpr Metal(const Pixel& a, const double f) noexcept;

   [[nodiscard]] API virtual bool Scatter(const Ray& ray,
                                          const HitRecord& rec,
                                          Pixel& attenuation,
                                          Ray& scattered) const noexcept override final;
};

#include "Metal.hpp"
#endif
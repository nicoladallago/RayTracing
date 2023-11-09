#ifndef LAMBERTIAN_SPHERE_H
#define LAMBERTIAN_SPHERE_H
#pragma once
#include "Objects/Sphere/Sphere.h"
#include "Materials/Lambertian.h"

class LambertianSphere: public Sphere {
 private:
   const Lambertian m_material;

 public:
   API constexpr LambertianSphere(const Point3& center, const double radius, const Pixel& albedo) noexcept;

   [[nodiscard]] API virtual inline const Lambertian& GetMaterial() const noexcept override final;
};

#include "LambertianSphere.hpp"
#endif
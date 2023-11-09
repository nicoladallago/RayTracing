#ifndef DIELECTRIC_SPHERE_H
#define DIELECTRIC_SPHERE_H
#pragma once
#include "Objects/Sphere/Sphere.h"
#include "Materials/Dielectric.h"

class DielectricSphere: public Sphere {
 private:
   const Dielectric m_material;

 public:
   API constexpr DielectricSphere(const Point3& center, const double radius, const double indexOfRefraction) noexcept;

   [[nodiscard]] API virtual inline const Dielectric& GetMaterial() const noexcept override final;
};

#include "DielectricSphere.hpp"
#endif
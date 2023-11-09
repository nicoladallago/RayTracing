#ifndef METAL_SPHERE_H
#define METAL_SPHERE_H
#pragma once
#include "Objects/Sphere/Sphere.h"
#include "Materials/Metal.h"

class MetalSphere: public Sphere {
 private:
   const Metal m_material;

 public:
   API constexpr MetalSphere(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) noexcept;

   [[nodiscard]] API virtual inline const Metal& GetMaterial() const noexcept override final;
};

#include "MetalSphere.hpp"
#endif
#ifndef METAL_SPHERE_HPP
#define METAL_SPHERE_HPP
#pragma once
#include "MetalSphere.h"

API constexpr MetalSphere::MetalSphere(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) noexcept:
    Sphere(center, radius),
    m_material(albedo, fuzz) {
}


API inline const Metal& MetalSphere::GetMaterial() const noexcept {
   return m_material;
}

#endif
#ifndef DIELECTRIC_SPHERE_HPP
#define DIELECTRIC_SPHERE_HPP
#pragma once
#include "DielectricSphere.h"

API constexpr DielectricSphere::DielectricSphere(const Point3& center,
                                                 const double radius,
                                                 const double indexOfRefraction) noexcept:
    Sphere(center, radius),
    m_material(indexOfRefraction) {
}


API inline const Dielectric& DielectricSphere::GetMaterial() const noexcept {
   return m_material;
}

#endif
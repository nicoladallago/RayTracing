#ifndef DIELECTRIC_SPHERE_HPP
#define DIELECTRIC_SPHERE_HPP
#pragma once
#include "DielectricSphere.h"

API constexpr DielectricSphere::DielectricSphere(const Point3& center, const double radius, const double indexOfRefraction) noexcept:
    BaseSphere(center, radius),
    m_material(indexOfRefraction) {
}

#endif
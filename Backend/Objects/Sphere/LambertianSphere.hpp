#ifndef LAMBERTIAN_SPHERE_HPP
#define LAMBERTIAN_SPHERE_HPP
#pragma once
#include "LambertianSphere.h"

API constexpr LambertianSphere::LambertianSphere(const Point3& center, const double radius, const Pixel& albedo) noexcept:
    BaseSphere(center, radius),
    m_material(albedo) {
}

#endif
#ifndef METAL_SPHERE_HPP
#define METAL_SPHERE_HPP
#pragma once
#include "MetalSphere.h"

API constexpr MetalSphere::MetalSphere(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) noexcept:
    BaseSphere(center, radius),
    m_material(albedo, fuzz) {
}

#endif
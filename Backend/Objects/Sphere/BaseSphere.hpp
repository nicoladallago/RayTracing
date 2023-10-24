#ifndef BASE_SPHERE_HPP
#define BASE_SPHERE_HPP
#pragma once
#include "BaseSphere.h"

API constexpr BaseSphere::BaseSphere(const Point3& center, const double radius) noexcept:
    m_center(center),
    m_radius(radius),
    m_radiusSquared(m_radius * m_radius) {
}

#endif
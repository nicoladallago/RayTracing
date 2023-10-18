#ifndef RAY_HPP
#define RAY_HPP
#pragma once
#include "Ray.h"

API constexpr Ray::Ray(const Point3& orig, const Vector3& dir) noexcept:
    m_orig(orig),
    m_dir(dir) {
}


API constexpr const Point3& Ray::GetOrigin() const noexcept {
   return m_orig;
}


API constexpr const Vector3& Ray::GetDirection() const noexcept {
   return m_dir;
}


API constexpr Point3 Ray::At(const double t) const noexcept {
   return m_orig + t * m_dir;
}

#endif
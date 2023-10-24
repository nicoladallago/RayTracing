#ifndef RAY_H
#define RAY_H
#pragma once
#include "Point3.h"

class Ray {
 private:
   Point3 m_orig;
   Vector3 m_dir;

 public:
   constexpr Ray() noexcept = default;
   constexpr Ray(const Point3& orig, const Vector3& dir) noexcept;

   [[nodiscard]] constexpr const Point3& GetOrigin() const noexcept;
   [[nodiscard]] constexpr const Vector3& GetDirection() const noexcept;

   [[nodiscard]] constexpr Point3 At(const double t) const noexcept;
};

#include "Ray.hpp"
#endif
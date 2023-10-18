#ifndef RAY_H
#define RAY_H
#pragma once
#include "Point3.h"

class Ray {
 private:
   Point3 m_orig;
   Vector3 m_dir;

 public:
   API constexpr Ray() noexcept = default;
   API constexpr Ray(const Point3& orig, const Vector3& dir) noexcept;

   [[nodiscard]] API constexpr const Point3& GetOrigin() const noexcept;
   [[nodiscard]] API constexpr const Vector3& GetDirection() const noexcept;

   [[nodiscard]] API constexpr Point3 At(const double t) const noexcept;
};

#include "Ray.hpp"
#endif
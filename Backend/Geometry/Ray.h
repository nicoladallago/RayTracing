#ifndef RAY_H
#define RAY_H
#pragma once
#include "Point3.h"

class Ray {
 private:
   Point3d m_orig;
   Vector3d m_dir;

 public:
   API constexpr Ray() noexcept = default;
   API constexpr Ray(const Point3d& orig, const Vector3d& dir) noexcept;

   [[nodiscard]] API constexpr const Point3d& GetOrigin() const noexcept;
   [[nodiscard]] API constexpr const Vector3d& GetDirection() const noexcept;

   [[nodiscard]] API constexpr Point3d At(const double t) const noexcept;
};

#include "Ray.hpp"
#endif
#ifndef HITTABLE_H
#define HITTABLE_H
#pragma once
#include "Geometry/Point3.h"
#include "Geometry/Ray.h"
#include "Utils/Interval.h"

class Hittable {
 public:
   struct HitRecord
   {
      Point3d p;
      Vector3d normal;
      double t = 0;
      bool frontFace = false;

      constexpr void SetFaceFront(const Ray& ray, const Vector3d& outwardNormal) noexcept;
   };

   API virtual ~Hittable() = default;

   [[nodiscard]] API virtual constexpr bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept = 0;
};

#include "Hittable.hpp"
#endif
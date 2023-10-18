#ifndef HIT_RECORD_H
#define HIT_RECORD_H
#pragma once
#include "Geometry/Point3.h"

class Ray;

class HitRecord {
 private:
   Point3 m_p;
   Vector3 m_normal;
   double m_t = 0;
   bool m_frontFace = false;

 public:
   API constexpr void SetRoot(const double t) noexcept;
   API constexpr void SetPoint(const Point3& p) noexcept;

   [[nodiscard]] API constexpr const Point3& GetPoint() const noexcept;
   [[nodiscard]] API constexpr const Vector3& GetNormal() const noexcept;
   [[nodiscard]] API constexpr double GetRoot() const noexcept;
   [[nodiscard]] API constexpr bool IsFrontFace() const noexcept;

   API void SetFaceFront(const Ray& ray, const Vector3& outwardNormal) noexcept;
};

#include "HitRecord.hpp"
#endif
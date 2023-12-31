#ifndef HIT_RECORD_HPP
#define HIT_RECORD_HPP
#pragma once
#include "HitRecord.h"
#include "Geometry/Ray.h"

constexpr void HitRecord::SetRoot(const double t) noexcept {
   m_t = t;
}


constexpr void HitRecord::SetPoint(const Point3& p) noexcept {
   m_p = p;
}


constexpr const Point3& HitRecord::GetPoint() const noexcept {
   return m_p;
}


constexpr const Vector3& HitRecord::GetNormal() const noexcept {
   return m_normal;
}


constexpr double HitRecord::GetRoot() const noexcept {
   return m_t;
}


constexpr bool HitRecord::IsFrontFace() const noexcept {
   return m_frontFace;
}


constexpr void HitRecord::SetFaceFront(const Ray& ray, const Vector3& outwardNormal) noexcept {
   m_frontFace = Dot(ray.GetDirection(), outwardNormal) < 0;
   m_normal = m_frontFace ? outwardNormal : -outwardNormal;
}

#endif
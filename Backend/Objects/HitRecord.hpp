#ifndef HIT_RECORD_HPP
#define HIT_RECORD_HPP
#pragma once
#include "HitRecord.h"

API constexpr void HitRecord::SetRoot(const double t) noexcept {
   m_t = t;
}


API constexpr void HitRecord::SetPoint(const Point3& p) noexcept {
   m_p = p;
}


API constexpr const Point3& HitRecord::GetPoint() const noexcept {
   return m_p;
}


API constexpr const Vector3& HitRecord::GetNormal() const noexcept {
   return m_normal;
}


API constexpr double HitRecord::GetRoot() const noexcept {
   return m_t;
}


API constexpr bool HitRecord::IsFrontFace() const noexcept {
   return m_frontFace;
}

#endif
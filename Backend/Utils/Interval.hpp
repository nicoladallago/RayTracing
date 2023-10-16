#ifndef INTERVAL_HPP
#define INTERVAL_HPP
#pragma once
#include "Interval.h"

API constexpr Interval::Interval() noexcept:
    m_min(std::numeric_limits<double>::max()),
    m_max(-std::numeric_limits<double>::max()) {
}


API constexpr Interval::Interval(const double min, const double max) noexcept:
    m_min(min),
    m_max(max) {
}


API constexpr double Interval::GetMin() const noexcept {
   return m_min;
}


API constexpr double Interval::GetMax() const noexcept {
   return m_max;
}


API constexpr double Interval::Clamp(const double val) const noexcept {
   if(val < m_min) {
      return m_min;
   }
   if(val > m_max) {
      return m_max;
   }
   return val;
}


API constexpr bool Interval::Contains(const double val) const noexcept {
   return m_min <= val && val <= m_max;
}


API constexpr bool Interval::Surrounds(const double val) const noexcept {
   return m_min < val && val < m_max;
}

#endif
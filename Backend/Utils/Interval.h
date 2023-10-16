#ifndef INTERVAL_H
#define INTERVAL_H
#pragma once

class Interval {
 private:
   const double m_min;
   const double m_max;

 public:
   API constexpr Interval() noexcept;
   API constexpr Interval(const double min, const double max) noexcept;

   [[nodiscard]] API constexpr double GetMin() const noexcept;
   [[nodiscard]] API constexpr double GetMax() const noexcept;

   [[nodiscard]] API constexpr bool Contains(const double val) const noexcept;
   [[nodiscard]] API constexpr bool Surrounds(const double val) const noexcept;
};

#include "Interval.hpp"

static constexpr Interval EMPTY = Interval(std::numeric_limits<double>::max(),
                                           -std::numeric_limits<double>::max());

static constexpr Interval UNIVERSE = Interval(-std::numeric_limits<double>::max(),
                                              std::numeric_limits<double>::max());

#endif
#ifndef UTILS_H
#define UTILS_H
#pragma once

namespace Utils {
   [[nodiscard]] API constexpr double DegreesToRadians(const double degrees) noexcept;
   [[nodiscard]] API constexpr double Sqrt(const double val) noexcept;
   [[nodiscard]] API constexpr double Abs(const double val) noexcept;
   [[nodiscard]] API constexpr double Pow(const double val, const int exp) noexcept;
   [[nodiscard]] API constexpr double Sin(const double val) noexcept;
   [[nodiscard]] API constexpr double Cos(const double val) noexcept;
   [[nodiscard]] API constexpr double Tan(const double val) noexcept;

   [[nodiscard]] API inline double Random() noexcept;                                   // TODO constexpr
   [[nodiscard]] API inline double Random(const double min, const double max) noexcept; // TODO constexpr

   [[nodiscard]] API constexpr bool Freq(const double x, const double y) noexcept;
}

#include "Utils.hpp"
#endif
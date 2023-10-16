#ifndef UTILS_H
#define UTILS_H
#pragma once

namespace Utils {
   [[nodiscard]] API constexpr double DegreesToRadians(const double degrees) noexcept;
   [[nodiscard]] API double Random() noexcept;                                   // TODO constexpr
   [[nodiscard]] API double Random(const double min, const double max) noexcept; // TODO constexpr
}

#include "Utils.hpp"
#endif
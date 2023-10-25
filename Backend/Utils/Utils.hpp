#ifndef UTILS_HPP
#define UTILS_HPP
#pragma once
#include "Utils.h"

API constexpr double Utils::DegreesToRadians(const double degrees) noexcept {
   return degrees * std::numbers::pi / 180.0;
}


API constexpr double Utils::Sqrt(const double val) noexcept {
   double curr = val;
   double prev = 0;

   while(curr != prev) {
      prev = curr;
      curr = 0.5 * (curr + val / curr);
   }
   return curr;
}


API constexpr double Utils::Abs(const double val) noexcept {
   return val < 0 ? -val : val;
}

#endif
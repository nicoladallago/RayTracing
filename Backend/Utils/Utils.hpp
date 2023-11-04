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


API constexpr double Utils::Pow(const double val, const int exp) noexcept {
   if(exp == 0) {
      return 1;
   }
   const double temp = Pow(val, exp / 2);
   if((exp % 2) == 0) {
      return temp * temp;
   }
   if(exp > 0) {
      return val * temp * temp;
   }
   return (temp * temp) / val;
}


API inline double Utils::Random() noexcept {
   static std::uniform_real_distribution<double> distribution(0.0, 1.0);
   static std::mt19937 generator;
   return distribution(generator);
}


API inline double Utils::Random(const double min, const double max) noexcept {
   return min + (max - min) * Random();
}

#endif
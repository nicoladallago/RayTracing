#include "Utils.h"

API constexpr double Utils::DegreesToRadians(const double degrees) noexcept {
   return degrees * std::numbers::pi / 180.0;
}


API double Utils::Random() noexcept {
   return std::rand() / (RAND_MAX + 1.0);
}


API double Utils::Random(const double min, const double max) noexcept {
   return min + (max - min) * Random();
}
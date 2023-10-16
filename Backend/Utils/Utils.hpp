#include "Utils.h"

#include <numbers> // TODO remove

API constexpr double Utils::DegreesToRadians(const double degrees) noexcept {
   return degrees * std::numbers::pi / 180.0;
}
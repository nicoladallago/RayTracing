#ifndef UTILS_HPP
#define UTILS_HPP
#pragma once
#include "Utils.h"

API constexpr double Utils::DegreesToRadians(const double degrees) noexcept {
   return degrees * std::numbers::pi / 180.0;
}

#endif
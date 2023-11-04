#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP
#pragma once
#include "Dielectric.h"

constexpr Dielectric::Dielectric(const double indexOfRefraction) noexcept:
    m_ir(indexOfRefraction),
    m_inverseIr(1 / indexOfRefraction) {
}


constexpr double Dielectric::Reflectance(const double cosine, const double refIdx) noexcept {
   // Use Schlick's approximation for reflectance.
   double r0 = (1 - refIdx) / (1 + refIdx);
   r0 = r0 * r0;
   return r0 + (1 - r0) * Utils::Pow((1 - cosine), REFLECTANCE_EXPONENT);
}

#endif
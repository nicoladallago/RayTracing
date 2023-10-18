#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP
#pragma once
#include "Dielectric.h"

API constexpr Dielectric::Dielectric(const double indexOfRefraction) noexcept:
    m_ir(indexOfRefraction),
    m_inverseIr(1 / indexOfRefraction) {
}

#endif
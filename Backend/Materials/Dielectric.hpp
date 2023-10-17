#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP
#pragma once
#include "Dielectric.h"

API constexpr Dielectric::Dielectric(const double indexOfRefraction) noexcept:
    m_ir(indexOfRefraction) {
}

#endif
#ifndef METAL_HPP
#define METAL_HPP
#pragma once
#include "Metal.h"

constexpr Metal::Metal(const Pixel& a, const double f) noexcept:
    m_albedo(a),
    m_fuzz(f) {
}

#endif
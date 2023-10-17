#ifndef LAMBERTIAN_HPP
#define LAMBERTIAN_HPP
#pragma once
#include "Lambertian.h"

API constexpr Lambertian::Lambertian(const Pixel& a) noexcept:
    m_albedo(a) {
}

#endif
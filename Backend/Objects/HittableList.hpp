#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"

constexpr void HittableList::Clear() noexcept {
   m_dielectricSpheres.clear();
   m_lambertianSpheres.clear();
   m_metalSpheres.clear();
}


constexpr void HittableList::AddDielectricSpehre(const Point3& center, const double radius, const double indexOfRefraction) {
   m_dielectricSpheres.emplace_back(center, radius, indexOfRefraction);
}


constexpr void HittableList::AddLambertianSpehre(const Point3& center, const double radius, const Pixel& albedo) {
   m_lambertianSpheres.emplace_back(center, radius, albedo);
}


constexpr void HittableList::AddMetalSpehre(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) {
   m_metalSpheres.emplace_back(center, radius, albedo, fuzz);
}

#endif
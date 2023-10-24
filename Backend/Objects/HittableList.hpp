#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"

constexpr void HittableList::Clear() noexcept {
   m_dielectricSpheres.clear();
   m_lambertianSpheres.clear();
   m_metalSpheres.clear();
}


constexpr void HittableList::AddDielectricSpehre(const DielectricSphere& sphere) {
   m_dielectricSpheres.emplace_back(sphere);
}


constexpr void HittableList::AddLambertianSpehre(const LambertianSphere& sphere) {
   m_lambertianSpheres.emplace_back(sphere);
}


constexpr void HittableList::AddMetalSpehre(const MetalSphere& sphere) {
   m_metalSpheres.emplace_back(sphere);
}

#endif
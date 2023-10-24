#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"

API constexpr void HittableList::Clear() noexcept {
   m_dielectricSpheres.clear();
   m_lambertianSpheres.clear();
   m_metalSpheres.clear();
}


API constexpr void HittableList::AddDielectricSpehre(const DielectricSphere& sphere) {
   m_dielectricSpheres.emplace_back(sphere);
}


API constexpr void HittableList::AddLambertianSpehre(const LambertianSphere& sphere) {
   m_lambertianSpheres.emplace_back(sphere);
}


API constexpr void HittableList::AddMetalSpehre(const MetalSphere& sphere) {
   m_metalSpheres.emplace_back(sphere);
}

#endif
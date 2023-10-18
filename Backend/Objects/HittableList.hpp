#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"

API constexpr void HittableList::Clear() noexcept {
   m_objects.clear();
}


API constexpr void HittableList::Add(std::unique_ptr<Sphere> upObject) {
   m_objects.emplace_back(std::move(upObject));
}

#endif
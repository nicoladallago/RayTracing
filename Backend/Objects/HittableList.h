#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#pragma once
#include "Objects/Sphere.h"

class HittableList {
 private:
   std::vector<std::unique_ptr<Sphere>> m_objects;

 public:
   API constexpr void Clear() noexcept;
   API constexpr void Add(std::unique_ptr<Sphere> upObject);

   [[nodiscard]] API bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;
};

#include "HittableList.hpp"
#endif
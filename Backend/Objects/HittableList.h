#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#pragma once
#include "Objects/Hittable.h"

class HittableList: public Hittable {
 private:
   std::vector<std::unique_ptr<Hittable>> m_objects;

 public:
   API constexpr void Clear() noexcept;
   API constexpr void Add(std::unique_ptr<Hittable> upObject);

   [[nodiscard]] API virtual bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept override final;
};

#include "HittableList.hpp"
#endif
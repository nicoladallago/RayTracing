#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#pragma once
#include "Objects/Hittable.h"

class HittableList: public Hittable {
 private:
   std::vector<std::shared_ptr<Hittable>> m_objects;

 public:
   API HittableList() noexcept = default;
   API explicit HittableList(const std::shared_ptr<Hittable>& spObject);

   API constexpr void Clear() noexcept;
   API constexpr void Add(const std::shared_ptr<Hittable>& spObject);

   [[nodiscard]] API virtual constexpr bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept override final;
};

#include "HittableList.hpp"
#endif
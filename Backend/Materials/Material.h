#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once
class Point3;
typedef Point3 Pixel;

class HitRecord;
class Ray;

class Material {
 public:
   API virtual ~Material() = default;

   [[nodiscard]] API virtual bool Scatter(const Ray& ray, const HitRecord& rec, Pixel& attenuation, Ray& scattered) const noexcept = 0;
};


#endif
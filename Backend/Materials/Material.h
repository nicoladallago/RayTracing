#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once
class Point3;
typedef Point3 Pixel;

class HitRecord;
class Ray;

class Material {
 public:
   virtual ~Material() noexcept = default;

   // Rule of 0
   Material() noexcept = default;
   Material(const Material&) noexcept = default;
   Material(Material&&) noexcept = default;
   Material& operator=(const Material&) noexcept = default;
   Material& operator=(Material&&) noexcept = default;

   [[nodiscard]] virtual bool Scatter(const Ray& ray, const HitRecord& rec, Pixel& attenuation, Ray& scattered) const noexcept = 0;
};


#endif
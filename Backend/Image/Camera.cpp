#include "Camera.h"
#include "Image/Image.h"
#include "Objects/HitRecord.h"
#include "Objects/HittableList.h"
#include "Materials/Material.h"
#include "Threads/ThreadsManager.h"


API Image Camera::Render(const HittableList& world) noexcept {
   ThreadsManager manager(world, *this, std::thread::hardware_concurrency());
   Image img(m_width, m_height);
   manager.Start(img);
   return img;
}


Pixel Camera::RayColor(const Ray& ray, const unsigned int depth, const HittableList& world) noexcept {
   if(depth <= 0) {
      return ZERO_PIXEL;
   }

   HitRecord rec;
   if(const Material* pMaterial = world.Hit(ray, INTERVAL, rec); pMaterial != nullptr) {
      Ray scattered;
      Pixel attenuation;

      if(pMaterial->Scatter(ray, rec, attenuation, scattered)) {
         return attenuation * RayColor(scattered, depth - 1, world);
      }
      return ZERO_PIXEL;
   }

   return RayBackground(ray);
}
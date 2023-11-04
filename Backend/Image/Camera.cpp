#include "Camera.h"
#include "Image/Image.h"
#include "Objects/HitRecord.h"
#include "Objects/HittableList.h"
#include "Materials/Material.h"
#include "Threads/ThreadsManager.h"

API Camera::Camera(const double aspectRatio,
                   const unsigned int width,
                   const unsigned int samplesPerPixels,
                   const unsigned int maxDepth,
                   const double vfov,
                   const Point3& lookFrom,
                   const Point3& lookAt,
                   const Vector3& vup,
                   const double defocusAngle,
                   const double focusDist) noexcept:
    m_aspectRatio(aspectRatio),
    m_width(width),
    m_samplesPerPixels(samplesPerPixels),
    m_maxDepth(maxDepth),
    m_vfov(vfov),
    m_lookFrom(lookFrom),
    m_lookAt(lookAt),
    m_vup(vup),
    m_defocusAngle(defocusAngle),
    m_focusDist(focusDist) {
   Initialize();
}


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


void Camera::Initialize() noexcept {
   m_height = static_cast<unsigned int>(m_width / m_aspectRatio);

   const double theta = Utils::DegreesToRadians(m_vfov);
   const double h = std::tan(theta / 2);
   const double viewportHeight = 2 * h * m_focusDist;
   const double viewportWidth = viewportHeight * static_cast<double>(m_width) / m_height;

   // Calculate the u,v,w unit basis vectors for the camera coordinate frame.
   m_w = UnitVector(m_lookFrom - m_lookAt);
   m_u = UnitVector(Cross(m_vup, m_w));
   m_v = Cross(m_w, m_u);

   const Vector3 viewportU = viewportWidth * m_u;
   const Vector3 viewportV = viewportHeight * -m_v;

   m_pixelDeltaU = viewportU / static_cast<double>(m_width);
   m_pixelDeltaV = viewportV / static_cast<double>(m_height);

   const Point3 viewportUpperLeft = m_lookFrom - (m_focusDist * m_w) - viewportU / 2 - viewportV / 2;
   m_pixel00Loc = viewportUpperLeft + 0.5 * (m_pixelDeltaU + m_pixelDeltaV);

   // Calculate the camera defocus disk basis vectors.
   const double defocusRadius = m_focusDist * std::tan(Utils::DegreesToRadians(m_defocusAngle / 2));
   m_defocusDiskU = m_u * defocusRadius;
   m_defocusDiskV = m_v * defocusRadius;
}
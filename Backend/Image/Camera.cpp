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


API void Camera::Render(const HittableList& world) noexcept {
   Image img(m_width, m_height);
   ThreadsManager(img, world, *this, 4);

   img.Save("image.ppm");
}


API Pixel Camera::RayColor(const Ray& ray, const unsigned int depth, const HittableList& world) noexcept {
   if(depth <= 0) {
      return ZERO_PIXEL;
   }

   HitRecord rec;
   if(world.Hit(ray, INTERVAL, rec)) {
      Ray scattered;
      Pixel attenuation;

      if(rec.mat->Scatter(ray, rec, attenuation, scattered)) {
         return attenuation * RayColor(scattered, depth - 1, world);
      }
      return ZERO_PIXEL;
   }

   const Vector3 unitDirection = UnitVector(ray.GetDirection());
   const double a = 0.5 * (unitDirection.GetY() + 1);
   return Pixel(1 - 0.5 * a, 1 - 0.3 * a, 1);
}


API double Camera::LinearToGamma(const double linear) noexcept {
   return std::sqrt(linear);
}


void Camera::Initialize() noexcept {
   m_height = static_cast<unsigned int>(m_width / m_aspectRatio);

   m_center = m_lookFrom;

   //const double focalLenght = (m_lookFrom - m_lookAt).Length();
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

   const Point3 viewportUpperLeft = m_center - (m_focusDist * m_w) - viewportU / 2 - viewportV / 2;
   m_pixel00Loc = viewportUpperLeft + 0.5 * (m_pixelDeltaU + m_pixelDeltaV);

   // Calculate the camera defocus disk basis vectors.
   const double defocusRadius = m_focusDist * std::tan(Utils::DegreesToRadians(m_defocusAngle / 2));
   m_defocusDiskU = m_u * defocusRadius;
   m_defocusDiskV = m_v * defocusRadius;
}


Vector3 Camera::PixelSampleSquare() const noexcept {
   const double px = -0.5 + Utils::Random();
   const double py = -0.5 + Utils::Random();
   return (px * m_pixelDeltaU) + (py * m_pixelDeltaV);
}


Point3 Camera::DefocusDiskSample() const {
   // Returns a random point in the camera defocus disk.
   const Point3 p = RandomInUnitDisk();
   return m_center + (p.GetX() * m_defocusDiskU) + (p.GetY() * m_defocusDiskV);
}


API Ray Camera::GetRay(const unsigned int i, const unsigned int j) const noexcept {
   const Point3 pixelCenter = m_pixel00Loc + (static_cast<double>(i) * m_pixelDeltaU) + (static_cast<double>(j) * m_pixelDeltaV);
   const Point3 rayOrigin = (m_defocusAngle <= 0) ? m_center : DefocusDiskSample();

   return Ray(rayOrigin, pixelCenter + PixelSampleSquare() - rayOrigin);
}
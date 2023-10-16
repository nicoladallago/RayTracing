#include "Camera.h"
#include "Utils/Utils.h"

API constexpr Camera::Camera(const double aspectRatio,
                             const unsigned int width,
                             const unsigned int samplesPerPixels) noexcept:
    m_aspectRatio(aspectRatio),
    m_width(width),
    m_samplesPerPixels(samplesPerPixels) {
   Initialize();
}

API void Camera::Render(const Hittable& world) noexcept {
   Image img(m_width, m_height);
   std::span<Image::Pixel> pixels = img.Get();

   for(unsigned int j = 0; j < m_height; ++j) {
      unsigned int offset = j * m_width;
      for(unsigned int i = 0; i < m_width; ++i) {
         Image::Pixel& p = pixels[offset + i];
         for(unsigned int sample = 0; sample < m_samplesPerPixels; ++sample) {
            const Ray ray = GetRay(i, j);
            RayColor(p, ray, world);
         }
         Normalize(p, m_samplesPerPixels);
      }
      std::cout << "Progress " << std::to_string(j * 100.0 / m_height) << '%' << '\n';
   }
   img.Save("image.ppm");
}


constexpr void Camera::Initialize() noexcept {
   m_height = static_cast<unsigned int>(m_width / m_aspectRatio);

   m_center = Point3d(0, 0, 0);

   const double focalLenght = 1;
   const double viewportHeight = 2;
   const double viewportWidth = viewportHeight * static_cast<double>(m_width) / m_height;

   const Vector3d viewportU(viewportWidth, 0, 0);
   const Vector3d viewportV(0, -viewportHeight, 0);

   m_pixelDeltaU = viewportU / static_cast<double>(m_width);
   m_pixelDeltaV = viewportV / static_cast<double>(m_height);

   const Point3d viewportUpperLeft = m_center - Vector3d(0, 0, focalLenght) - viewportU / 2.0 - viewportV / 2.0;
   m_pixel00Loc = viewportUpperLeft + 0.5 * (m_pixelDeltaU + m_pixelDeltaV);
}


constexpr Ray Camera::GetRay(const unsigned int i, const unsigned int j) const noexcept {
   const Point3d pixelCenter = m_pixel00Loc + (static_cast<double>(i) * m_pixelDeltaU) +
       (static_cast<double>(j) * m_pixelDeltaV);
   const Point3d pixelSample = pixelCenter + PixelSampleSquare();

   const Point3d rayOrigin = m_center;
   const Vector3d rayDirection = pixelSample - rayOrigin;

   return Ray(rayOrigin, rayDirection);
}


Vector3d Camera::PixelSampleSquare() const noexcept {
   const double px = -0.5 + Utils::Random();
   const double py = -0.5 + Utils::Random();
   return (px * m_pixelDeltaU) + (py * m_pixelDeltaV);
}


constexpr void Camera::RayColor(Image::Pixel& p, const Ray& ray, const Hittable& world) noexcept {
   Hittable::HitRecord rec;

   if(world.Hit(ray, Interval(0, std::numeric_limits<double>::max()), rec)) {
      p.r += (0.5 * (rec.normal.GetX() + 1));
      p.g += (0.5 * (rec.normal.GetY() + 1));
      p.b += (0.5 * (rec.normal.GetZ() + 1));
      return;
   }

   const Vector3d unitDirection = UnitVector(ray.GetDirection());
   const double a = 0.5 * (unitDirection.GetY() + 1);
   p.r += ((1 - a) + 0.5 * a);
   p.g += ((1 - a) + 0.7 * a);
   p.b += ((1 - a) + a);
}


constexpr void Camera::Normalize(Image::Pixel& p, const unsigned int samplesPerPixel) noexcept {
   const double scale = 1.0 / samplesPerPixel;
   p.r *= scale;
   p.g *= scale;
   p.b *= scale;

   const Interval intensity(0, 1);
   p.r = 255 * intensity.Clamp(p.r);
   p.g = 255 * intensity.Clamp(p.g);
   p.b = 255 * intensity.Clamp(p.b);
}
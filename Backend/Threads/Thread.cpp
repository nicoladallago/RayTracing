#include "Thread.h"
#include "Image/Camera.h"
#include "Objects/Hittable.h"
#include "Utils/Interval.h"

API Thread::Data::Data(Pixel& p, const unsigned int i, const unsigned int j) noexcept:
    m_p(p),
    m_i(i),
    m_j(j) {
}


API Thread::Thread(const size_t id, const Camera& camera, const Hittable& world) noexcept:
    m_id(id),
    m_camera(camera),
    m_world(world) {
}


API Thread::~Thread() {
   m_thread.join();
}


API void Thread::Add(Pixel& pixel, const unsigned int i, const unsigned int j) {
   m_pixels.emplace(pixel, i, j);
}


API void Thread::StartRender() {
   m_thread = std::thread(&Thread::Render, this);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__) // Windows only
   HANDLE handle = m_thread.native_handle();
   //if(SetThreadPriority(handle, THREAD_PRIORITY_TIME_CRITICAL) == 0) {
   //   throw std::exception(std::to_string(GetLastError()).c_str());
   //}
   const DWORD mask = (static_cast<DWORD>(1) << m_id);
   if(SetThreadAffinityMask(handle, mask) == 0) {
      throw std::exception(std::to_string(GetLastError()).c_str());
   }
#endif
}


API size_t Thread::GetId() const noexcept {
   return m_id;
}


API bool Thread::RenderDone() const noexcept {
   return m_pixels.empty();
}


API size_t Thread::ItemsRemaining() const noexcept {
   return m_pixels.size();
}


void Thread::Render() noexcept {
   while(!m_pixels.empty()) {
      Data& data = m_pixels.front();
      RenderPixel(data.m_p, data.m_i, data.m_j);

      m_pixels.pop();
   }
}


void Thread::RenderPixel(Pixel& p, const unsigned int i, const unsigned int j) const noexcept {
   for(unsigned int sample = 0; sample < m_camera.GetSamplesPerPixels(); ++sample) {
      p += Camera::RayColor(m_camera.GetRay(i, j), m_camera.GetMaxDepth(), m_world);
   }

   p *= (1.0 / m_camera.GetSamplesPerPixels());

   p.SetX(Camera::LinearToGamma(p.GetX()));
   p.SetY(Camera::LinearToGamma(p.GetY()));
   p.SetZ(Camera::LinearToGamma(p.GetZ()));

   const Interval intensity(0, 1);
   p.SetX(255 * intensity.Clamp(p.GetX()));
   p.SetY(255 * intensity.Clamp(p.GetY()));
   p.SetZ(255 * intensity.Clamp(p.GetZ()));
}

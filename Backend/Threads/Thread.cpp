#include "Thread.h"
#include "Image/Camera.h"
#include "Objects/HittableList.h"

API Thread::Thread(const size_t id, const Camera& camera, const HittableList& world) noexcept:
    m_id(id),
    m_camera(camera),
    m_samplesPerPixel(camera.GetSamplesPerPixels()),
    m_maxDepth(m_camera.GetMaxDepth()),
    m_world(world) {
}


API Thread::~Thread() {
   m_thread.join();
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


void Thread::Render() noexcept {
   while(!m_pixels.empty()) {
      Data& data = m_pixels.back();
      RenderPixel(data.m_p, data.m_i, data.m_j);

      m_pixels.pop_back();
   }
}


void Thread::RenderPixel(Pixel& p, const unsigned int i, const unsigned int j) const noexcept {
   for(unsigned int sample = 0; sample < m_samplesPerPixel; ++sample) {
      p += Camera::RayColor(m_camera.GetRay(i, j), m_maxDepth, m_world);
   }
   p /= m_samplesPerPixel;

   p.SetX(Camera::LinearToGamma(p.GetX()));
   p.SetY(Camera::LinearToGamma(p.GetY()));
   p.SetZ(Camera::LinearToGamma(p.GetZ()));

   p.SetX(MAX_PIXEL_VAL * CLAMP.Clamp(p.GetX()));
   p.SetY(MAX_PIXEL_VAL * CLAMP.Clamp(p.GetY()));
   p.SetZ(MAX_PIXEL_VAL * CLAMP.Clamp(p.GetZ()));
}

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
#ifdef WINDOWS_BUILD
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

#include "Camera.h"
#include "Image/Image.h"
#include "Threads/ThreadsManager.h"

API Image Camera::Render(const HittableList& world) noexcept {
   ThreadsManager manager(world, *this, std::thread::hardware_concurrency());
   Image img(m_width, m_height);
   manager.Start(img);
   return img;
}
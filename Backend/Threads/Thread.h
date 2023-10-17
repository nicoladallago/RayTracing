#ifndef THREAD_H
#define THREAD_H
#pragma once
#include "Image/Image.h"

class Camera;
class Hittable;

class Thread {
 private:
   struct Data
   {
      Pixel& m_p;
      const unsigned int m_i;
      const unsigned int m_j;

      API Data(Pixel& p, const unsigned int i, const unsigned int j) noexcept;
   };

   std::thread m_thread;
   std::queue<Data> m_pixels;

   const unsigned int m_id;
   const Camera& m_camera;
   const Hittable& m_world;

 public:
   API Thread(const unsigned int id, const Camera& camera, const Hittable& world) noexcept;
   API ~Thread();

   API void Add(Pixel& pixel, const unsigned int i, const unsigned int j);
   API void StartRender();

   [[nodiscard]] API unsigned int GetId() const noexcept;
   [[nodiscard]] API bool RenderDone() const noexcept;
   [[nodiscard]] API size_t ItemsRemaining() const noexcept;

 private:
   void Render() noexcept;
   void RenderPixel(Pixel& p, const unsigned int i, const unsigned int j) const noexcept;
};

#endif

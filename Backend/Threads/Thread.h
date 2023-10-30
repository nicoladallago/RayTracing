#ifndef THREAD_H
#define THREAD_H
#pragma once
#include "Image/Image.h"
#include "Utils/Interval.h"

class Camera;
class HittableList;

class Thread {
 private:
   static constexpr Interval CLAMP = Interval(0, 1);

   struct Data
   {
      Pixel& m_p;
      const unsigned int m_i;
      const unsigned int m_j;

      API constexpr Data(Pixel& p, const unsigned int i, const unsigned int j) noexcept;
   };

   std::thread m_thread;
   std::queue<Data> m_pixels;

   const size_t m_id;
   const Camera& m_camera;
   const unsigned int m_samplesPerPixel;
   const HittableList& m_world;

 public:
   API Thread(const size_t id, const Camera& camera, const HittableList& world) noexcept;
   API ~Thread();

   API void Add(Pixel& pixel, const unsigned int i, const unsigned int j);
   API void StartRender();

   [[nodiscard]] API constexpr size_t GetId() const noexcept;
   [[nodiscard]] API bool RenderDone() const noexcept;
   [[nodiscard]] API size_t ItemsRemaining() const noexcept;

 private:
   void Render() noexcept;
   void RenderPixel(Pixel& p, const unsigned int i, const unsigned int j) const noexcept;
};

#include "Thread.hpp"
#endif

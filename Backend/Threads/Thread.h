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
   static constexpr double MAX_PIXEL_VAL = 255;

   struct Data
   {
      Pixel& m_p;
      const int m_i;
      const int m_j;

      API constexpr Data(Pixel& p, const int i, const int j) noexcept;
   };

   std::thread m_thread;
   std::vector<Data> m_pixels;

   const size_t m_id;
   const Camera& m_camera;
   const int m_samplesPerPixel;
   const int m_maxDepth;
   const HittableList& m_world;

 public:
   API Thread(const size_t id, const Camera& camera, const HittableList& world) noexcept;
   API ~Thread();

   API constexpr void Add(Pixel& pixel, const int i, const int j);
   API void StartRender();

   [[nodiscard]] API constexpr size_t GetId() const noexcept;
   [[nodiscard]] API constexpr bool RenderDone() const noexcept;
   [[nodiscard]] API constexpr size_t ItemsRemaining() const noexcept;

 private:
   inline void Render() noexcept;
   inline void RenderPixel(Pixel& p, const int i, const int j) const noexcept;
};

#include "Thread.hpp"
#endif

#ifndef THREADS_MANAGER_H
#define THREADS_MANAGER_H
#pragma once
#include "Threads/Thread.h"

class Image;
class HittableList;
class Camera;

class ThreadsManager {
 private:
   static constexpr int SLEEP_S = 1;
   static constexpr int WRITE_EVERY_S = 5;
   static constexpr std::string CLR = "\33[2K\r";

   std::vector<std::unique_ptr<Thread>> m_threads;

 public:
   ThreadsManager(const HittableList& world, const Camera& camera, size_t threads);

   void Start(Image& img);

 private:
   void FillThreads(Image& img) noexcept;
};

#endif
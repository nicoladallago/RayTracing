#ifndef THREADS_MANAGER_H
#define THREADS_MANAGER_H
#pragma once
#include "Threads/Thread.h"

class Image;
class HittableList;
class Camera;

class ThreadsManager {
 private:
   static constexpr int SLEEP_S = 5;

   std::vector<std::unique_ptr<Thread>> m_threads;

 public:
   ThreadsManager(Image& img, const HittableList& world, const Camera& camera, size_t threads);
};

#endif
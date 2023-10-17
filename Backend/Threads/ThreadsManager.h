#ifndef THREADS_MANAGER_H
#define THREADS_MANAGER_H
#pragma once
#include "Threads/Thread.h"

class Image;
class Hittable;
class Camera;

class ThreadsManager {
 private:
   std::vector<std::unique_ptr<Thread>> m_threads;

 public:
   ThreadsManager(Image& img, const Hittable& world, const Camera& camera, const size_t threads = 4);
};

#endif
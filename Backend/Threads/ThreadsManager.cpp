#include "ThreadsManager.h"
#include "Image/Image.h"

ThreadsManager::ThreadsManager(Image& img, const Hittable& world, const Camera& camera, const size_t threads) {
   for(size_t i = 0; i < threads; ++i) {
      m_threads.push_back(std::make_unique<Thread>(i, camera, world));
   }

   // Set data
   const size_t pixelsPerThread = img.GetSize() / threads;

   std::span<Pixel> pixels = img.Get();
   size_t index = 0;
   size_t threadIdx = 0;

   for(unsigned int j = 0; j < img.GetHeight(); ++j) {
      unsigned int offset = j * img.GetWidth();
      for(unsigned int i = 0; i < img.GetWidth(); ++i) {
         m_threads.at(threadIdx)->Add(pixels[offset + i], i, j);

         ++index;
         if(index >= pixelsPerThread) {
            threadIdx = std::min(threadIdx + 1, threads - 1);
            index = 0;
         }
      }
   }

   // Start
   for(const std::unique_ptr<Thread>& upThread : m_threads) {
      upThread->StartRender();
   }

   // Wait
   while(true) {
      std::this_thread::sleep_for(std::chrono::seconds(1));

      bool computationDone = true;
      for(const std::unique_ptr<Thread>& upThread : m_threads) {
         if(!upThread->RenderDone()) {
            computationDone = false;
         }

         // compute percentage remaing
         const double remains = static_cast<double>(upThread->ItemsRemaining()) * 100.0 / static_cast<double>(pixelsPerThread);
         std::cout << "Thread " + std::to_string(upThread->GetId()) + " " + std::to_string(remains) << "%\n";
      }
      if(computationDone) {
         break;
      }
   }
}
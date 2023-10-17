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
   const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

   while(true) {
      std::this_thread::sleep_for(std::chrono::seconds(5));

      bool computationDone = true;
      std::vector<double> time(2 * threads);
      for(const std::unique_ptr<Thread>& upThread : m_threads) {
         if(!upThread->RenderDone()) {
            computationDone = false;
         }

         // compute percentage remaing
         time.at(2 * upThread->GetId() + 0) = static_cast<double>(upThread->ItemsRemaining());
         time.at(2 * upThread->GetId() + 1) = static_cast<double>(upThread->ItemsRemaining()) * 100.0 / static_cast<double>(pixelsPerThread);
      }

      for(size_t i = 0; i < time.size(); ++i) {
         if(i % 2 == 0) {
            std::cout << std::to_string(static_cast<size_t>(time[i])) << " ";
         }
         else {
            std::cout << std::format("[ {}%]   ", static_cast<size_t>(time[i] * 100) / 100.0);
         }
      }
      std::cout << '\n';

      if(computationDone) {
         break;
      }
   }

   const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
   std::cout << "Rendered in " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " [s]" << std::endl;
}
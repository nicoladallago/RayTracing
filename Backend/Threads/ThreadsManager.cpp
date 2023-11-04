#include "ThreadsManager.h"
#include "Image/Image.h"

ThreadsManager::ThreadsManager(const HittableList& world, const Camera& camera, size_t threads) {
   threads = std::max<size_t>(1, threads);
   m_threads.reserve(threads);
   for(size_t i = 0; i < threads; ++i) {
      m_threads.emplace_back(std::make_unique<Thread>(i, camera, world));
   }
}


void ThreadsManager::Start(Image& img) {
   if(m_threads.empty()) {
      return;
   }

   const size_t threads = m_threads.size();

   // Set data
   const std::span<Pixel> pixels = img.Get();
   size_t threadIdx = 0;
   for(unsigned int j = 0; j < img.GetHeight(); ++j) {
      const unsigned int offset = j * img.GetWidth();
      for(unsigned int i = 0; i < img.GetWidth(); ++i) {
         m_threads[threadIdx++]->Add(pixels[offset + i], i, j);
         if(threadIdx >= threads) {
            threadIdx = 0;
         }
      }
   }

   // Start
   for(const std::unique_ptr<Thread>& upThread : m_threads) {
      upThread->StartRender();
   }

   // Wait
   const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

   int seconds = 0;
   const size_t pixelsPerThread = img.GetSize() / threads;
   while(true) {
      std::this_thread::sleep_for(std::chrono::seconds(SLEEP_S));

      bool computationDone = true;
      std::vector<double> time(threads);
      for(const std::unique_ptr<Thread>& upThread : m_threads) {
         if(!upThread->RenderDone()) {
            computationDone = false;
         }

         // compute percentage remaing
         time.at(upThread->GetId()) = static_cast<double>(upThread->ItemsRemaining()) * 100.0 / static_cast<double>(pixelsPerThread);
      }

      ++seconds;
      if(seconds < WRITE_EVERY_S) {
         continue;
      }
      seconds = 0;

      std::cout << "\33[2K\r";
      for(const double percentage : time) {
         std::cout << '[' << std::setprecision(PERCENTAGE_PRECISION) << percentage << "%] ";
      }

      if(computationDone) {
         break;
      }
   }

   std::cout << "\33[2K\r"
             << "Rendered in " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count() << " [s]\n";
}
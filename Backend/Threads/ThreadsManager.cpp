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
   using namespace std::chrono;

   if(m_threads.empty()) {
      return;
   }

   // Set data
   FillThreads(img);

   // Start
   for(const std::unique_ptr<Thread>& upThread : m_threads) {
      upThread->StartRender();
   }

   // Wait
   const steady_clock::time_point start = steady_clock::now();

   int second = 0;
   const size_t threads = m_threads.size();
   const double pixelsPerThread = static_cast<double>(img.GetSize() / m_threads.size());

   std::vector<double> time(threads);
   while(true) {
      std::this_thread::sleep_for(seconds(SLEEP_S));

      bool computationDone = true;
      for(const std::unique_ptr<Thread>& upThread : m_threads) {
         if(!upThread->RenderDone()) {
            computationDone = false;
         }

         // compute percentage remaing
         time[upThread->GetId()] = static_cast<double>(upThread->ItemsRemaining()) * 100.0 / pixelsPerThread;
      }
      if(computationDone) {
         break;
      }

      ++second;
      if(second < WRITE_EVERY_S) {
         continue;
      }
      second = 0;

      std::string text;
      for(const double percentage : time) {
         text += '[' + std::to_string(percentage) + "%] ";
      }
      std::cout << CLR << text;
   }

   const steady_clock::time_point end = steady_clock::now();
   std::cout << CLR << "Rendered in " << duration_cast<seconds>(end - start).count() << "[s]\n ";
}


void ThreadsManager::FillThreads(Image& img) noexcept {
   std::vector<Pixel>& pixels = img.Get();
   const size_t height = img.GetHeight();
   const size_t width = img.GetWidth();

   const size_t threads = m_threads.size();
   if(threads == 0) {
      return;
   }

   size_t threadIdx = 0;

   for(size_t j = 0; j < height; ++j) {
      const size_t offset = j * width;
      for(size_t i = 0; i < width; ++i) {
         m_threads[threadIdx++]->Add(pixels[offset + i], static_cast<int>(i), static_cast<int>(j));
         threadIdx %= threads;
      }
   }
}
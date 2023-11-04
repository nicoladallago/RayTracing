#include "Image.h"


API void Image::Save(const std::filesystem::path& path) const {
   std::ofstream file(path, std::ios::binary);
   if(!file.is_open()) {
      throw std::exception(std::format("Failed to open the file {}", path.string()).c_str());
   }

   std::streambuf* pPrevBuffer = std::cout.rdbuf();
   std::cout.rdbuf(file.rdbuf());

   std::cout << "P3\n"
             << m_width << ' ' << m_height << "\n255\n";
   for(const Pixel& p : m_data) {
      std::cout << static_cast<int>(p.GetX()) << ' ' << static_cast<int>(p.GetY()) << ' ' << static_cast<int>(p.GetZ()) << '\n';
   }

   std::cout << std::flush;
   file.close();
   std::cout.rdbuf(pPrevBuffer); //reset to standard output again
}
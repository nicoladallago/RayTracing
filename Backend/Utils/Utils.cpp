#include "Utils.h"

API double Utils::Random() noexcept {
   static std::uniform_real_distribution<double> distribution(0.0, 1.0);
   static std::mt19937 generator;
   return distribution(generator);
}


API double Utils::Random(const double min, const double max) noexcept {
   return min + (max - min) * Random();
}
#include "Utils.h"

API double Utils::Random() noexcept {
   return std::rand() / (RAND_MAX + 1.0);
}


API double Utils::Random(const double min, const double max) noexcept {
   return min + (max - min) * Random();
}
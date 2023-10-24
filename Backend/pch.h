#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__) // Windows only
   #define NOMINMAX
   #pragma warning(push)
   #pragma warning(disable : 4668)
   #include <Windows.h>
   #pragma warning(pop)
#endif

#include "Export.h"

#include <cmath>
#include <map>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <span>
#include <vector>
#include <memory>
#include <numbers>
#include <random>
#include <queue>
#include <iomanip>
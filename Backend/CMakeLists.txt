set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)

set(SOURCES 
    "Communication/Model.cpp"
	"Communication/Signal.hpp"

    "Geometry/Point2.hpp"
    "Geometry/Point3.hpp"
    "Geometry/Rect.hpp")

add_library(Backend SHARED)
target_sources(Backend PRIVATE ${SOURCES})
target_include_directories(Backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(Backend PUBLIC pch.h)

# clang tidy setup
if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
   set(CMAKE_CXX_CLANG_TIDY clang-tidy)
   set(CMAKE_CXX_CLANG_TIDY_EXPORT_FIXES_DIR clang-tidy)
endif()

# External dependencies:

# PalSigslot
find_package(PalSigslot CONFIG REQUIRED)
target_link_libraries(Backend PUBLIC Pal::Sigslot)
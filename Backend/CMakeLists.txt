set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)

set(SOURCES 
    "Geometry/Point3.hpp"
    "Geometry/Ray.hpp"

    "Image/Camera.cpp"
    "Image/Camera.hpp"
    "Image/Image.cpp"
    "Image/Image.hpp"

    "Materials/Dielectric.hpp"
    "Materials/Lambertian.hpp"
    "Materials/Metal.hpp"

    "Objects/HitRecord.hpp"
    "Objects/HittableList.hpp"
    "Objects/Sphere.hpp"

    "Threads/Thread.cpp"
    "Threads/Thread.hpp"
    "Threads/ThreadsManager.cpp"

    "Utils/Interval.hpp"
    "Utils/Utils.hpp"
    "Utils/XoshiroCpp.hpp"
)

add_library(Backend SHARED)
target_sources(Backend PRIVATE ${SOURCES})
target_include_directories(Backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(Backend PUBLIC pch.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)

set(SOURCES 
    "Geometry/Point3.hpp"
    "Geometry/Ray.hpp"
    "Geometry/Rect.hpp"

    "Image/Camera.cpp"
    "Image/Camera.hpp"
    "Image/Image.cpp"
    "Image/Image.hpp"

    "Materials/Dielectric.cpp"
    "Materials/Dielectric.hpp"
    "Materials/Lambertian.cpp"
    "Materials/Lambertian.hpp"
    "Materials/Metal.cpp"
    "Materials/Metal.hpp"

    "Objects/HitRecord.cpp"
    "Objects/HitRecord.hpp"
    "Objects/HittableList.cpp"
    "Objects/HittableList.hpp"
    "Objects/Sphere.cpp"

    "Threads/Thread.cpp"
    "Threads/ThreadsManager.cpp"

    "Utils/Interval.hpp"
    "Utils/Utils.cpp"
    "Utils/Utils.hpp"
)

add_library(Backend SHARED)
target_sources(Backend PRIVATE ${SOURCES})
target_include_directories(Backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(Backend PUBLIC pch.h)
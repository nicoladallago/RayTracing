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
    "Geometry/Ray.hpp"
    "Geometry/Rect.hpp"

    "Image/Camera.hpp"
    "Image/Image.cpp"
    "Image/Image.hpp"

    "Materials/Lambertian.hpp"
    "Materials/Metal.hpp"

    "Objects/Hittable.hpp"
    "Objects/Sphere.hpp"

    "Utils/Interval.hpp"
    "Utils/Utils.cpp"
    "Utils/Utils.hpp"
)

add_library(Backend SHARED)
target_sources(Backend PRIVATE ${SOURCES})
target_include_directories(Backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(Backend PUBLIC pch.h)

# External dependencies:

# PalSigslot
find_package(PalSigslot CONFIG REQUIRED)
target_link_libraries(Backend PUBLIC Pal::Sigslot)
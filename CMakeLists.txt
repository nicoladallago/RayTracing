cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23) # C++23 Project

# Version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

project(RayTracing
        VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
        DESCRIPTION "RayTracing"
        LANGUAGES CXX)

# Run version
include(${CMAKE_CURRENT_SOURCE_DIR}/version.cmake.txt)
CreateVersionHeader("${CMAKE_CURRENT_SOURCE_DIR}/Version.h" ${VERSION_MAJOR} ${VERSION_MINOR} ${VERSION_PATCH})

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)

# clang tidy setup
#if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
#   set(CMAKE_CXX_CLANG_TIDY clang-tidy)
#   set(CMAKE_CXX_CLANG_TIDY_EXPORT_FIXES_DIR clang-tidy)
#endif()

add_subdirectory(Backend)
#add_subdirectory(Frontend)

# Create executable
set(SOURCES "main.cpp")
#add_executable(RayTracing WIN32 ${SOURCES})
add_executable(RayTracing ${SOURCES})
#target_include_directories(RayTracing PUBLIC ${CMAKE_SOURCE_DIR}/Frontend)
target_include_directories(RayTracing PUBLIC ${CMAKE_SOURCE_DIR}/Backend)
target_link_libraries(RayTracing PUBLIC Backend)
#target_link_libraries(RayTracing PUBLIC Frontend)

# Avoid to open console in release mode
#if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
#    set_property(TARGET RayTracing PROPERTY WIN32_EXECUTABLE true)
#endif()
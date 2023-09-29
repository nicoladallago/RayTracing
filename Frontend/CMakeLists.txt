set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)

set(SOURCES 
    "ImGui/Application.cpp")

add_library(Frontend SHARED)
target_sources(Frontend PRIVATE ${SOURCES})
target_include_directories(Frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(Frontend PUBLIC pch.h)

# External dependencies:

# Backend
target_include_directories(Frontend PUBLIC ${CMAKE_SOURCE_DIR}/Backend)
target_link_libraries(Frontend PUBLIC Backend)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)

set(SOURCES 
    "App/Application.cpp"
    "App/WindowHandler.cpp"

    "Base/Layout.cpp"
    "Base/Layout.hpp"
    "Base/Widget.cpp"
    "Base/Widget.hpp"

    "Color/Color.hpp"

    "Draw/Draw2.hpp"

    "Widgets/Button.hpp"
    "Widgets/Button.cpp"
    "Widgets/MainWidget.cpp")

add_library(Frontend SHARED)
target_sources(Frontend PRIVATE ${SOURCES})
target_include_directories(Frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(Frontend PUBLIC pch.h)

# clang tidy setup
if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
   set(CMAKE_CXX_CLANG_TIDY clang-tidy)
   set(CMAKE_CXX_CLANG_TIDY_EXPORT_FIXES_DIR clang-tidy)
endif()

# External dependencies:

# Backend
target_include_directories(Frontend PUBLIC ${CMAKE_SOURCE_DIR}/Backend)
target_link_libraries(Frontend PUBLIC Backend)
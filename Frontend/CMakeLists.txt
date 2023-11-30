set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/out)

set(SOURCES 
	"App/App.cpp"
	
	"Windows/WindowMain.cpp"
)

add_library(Frontend SHARED)
target_sources(Frontend PRIVATE ${SOURCES})
target_include_directories(Frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(Frontend PUBLIC pch.h)

# Backend
target_link_libraries(Frontend PUBLIC Backend)

# fltk
find_package(fltk CONFIG REQUIRED)
target_link_libraries(Frontend PUBLIC fltk)
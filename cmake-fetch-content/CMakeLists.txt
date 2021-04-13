#
# Example program CMake configuration with CMake module FetchContent
#
# Source:
#   https://github.com/fltk/fltk/issues/164
#   https://github.com/fltk/fltk/issues/164#issuecomment-732495144
#
# CMake Documentation:
#
#   https://cmake.org/cmake/help/latest/module/FetchContent.html
#
# The CMake module FetchContent is "New in version 3.11".

cmake_minimum_required(VERSION 3.11)
project(hello)

# Edit this as required by your build or change FLTK_COMMIT in the
# CMake cache (e.g. with cmake-gui)

set (FLTK_COMMIT "branch-1.3" CACHE STRING "FLTK branch name, tag, or commit")

include(FetchContent)

set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
if(UNIX AND NOT APPLE) 
    set(OPTION_USE_PANGO ON CACHE BOOL " " FORCE)
endif()

FetchContent_Declare(FLTK
    GIT_REPOSITORY      https://github.com/fltk/fltk
    GIT_TAG             "${FLTK_COMMIT}"
)

FetchContent_MakeAvailable(FLTK)

add_executable(hello WIN32 MACOSX_BUNDLE ../src/hello.cxx)
target_include_directories(hello PRIVATE ${fltk_BINARY_DIR} ${fltk_SOURCE_DIR})
target_link_libraries(hello PRIVATE fltk) # + fltk_gl fltk_images fltk_png fltk_jpeg fltk_z 

if(APPLE)
    target_link_libraries(hello PRIVATE "-framework Cocoa") # needed for macOS
endif()

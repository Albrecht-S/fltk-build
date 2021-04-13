#
# Example program CMake configuration with CMake module ExternalProject
#
# Author:
#
#   Albrecht Schlosser
#
# CMake Documentation:
#
#   https://cmake.org/cmake/help/latest/module/ExternalProject.html

cmake_minimum_required(VERSION 3.2.3)
project(hello)

# Edit this as required by your build or change FLTK_COMMIT in the
# CMake cache (e.g. with cmake-gui)

set (FLTK_COMMIT "branch-1.3" CACHE STRING "FLTK branch name, tag, or commit")

set (BUILD_FLTK "${CMAKE_CURRENT_BINARY_DIR}/fltk/${FLTK_COMMIT}")

include(ExternalProject)

ExternalProject_Add(FLTK
    GIT_REPOSITORY      https://github.com/fltk/fltk
    GIT_TAG             "${FLTK_COMMIT}"
    GIT_SHALLOW         TRUE
    PREFIX              ${BUILD_FLTK}/build
    INSTALL_DIR         ${BUILD_FLTK}/bin
    CMAKE_ARGS
                       -DCMAKE_INSTALL_PREFIX=${BUILD_FLTK}/bin
                       -DFLTK_BUILD_TEST=OFF
                       -DFLTK_BUILD_EXAMPLES=OFF
)

# Find FLTK

if(APPLE)
  if(NOT FLTK_DIR)
    set (FLTK_DIR ${BUILD_FLTK}/bin/FLTK.framework/Resources/CMake/
      CACHE PATH
      "FLTK binary folder with FLTKConfig.cmake" FORCE)
  else()
    set (FLTK_DIR ${BUILD_FLTK}/bin/FLTK.framework/Resources/CMake/
      CACHE PATH
      "FLTK binary folder with FLTKConfig.cmake")
  endif()
else()
  set (FLTK_DIR ${BUILD_FLTK}/bin/share/fltk
      CACHE PATH
      "FLTK binary folder with FLTKConfig.cmake")
endif()

find_package(FLTK CONFIG)

if(FLTK_FOUND)

  add_executable(hello WIN32 MACOSX_BUNDLE ../src/hello.cxx)

  if (APPLE)
    target_link_libraries(hello "-framework cocoa")
  endif (APPLE)

  target_include_directories(hello PRIVATE ${FLTK_INCLUDE_DIRS})

  target_link_libraries(hello fltk)

endif()

# Debug ...

message(STATUS "BUILD_FLTK                  = ${BUILD_FLTK}")
message(STATUS "FLTK_DIR                    = ${FLTK_DIR}")
message(STATUS "FLTK_FOUND                  = ${FLTK_FOUND}")
message(STATUS "FLTK_COMMIT                 = '${FLTK_COMMIT}'")
message(STATUS "FLTK_INCLUDE_DIRS           = ${FLTK_INCLUDE_DIRS}")

#
# Simple example FLTK program CMake configuration
#
# Author:
#
#   Albrecht Schlosser
#
# FLTK must already have been built with CMake

cmake_minimum_required(VERSION 3.2.3)
project(hello)

# The following line is required only if
#  (a) you didn't install FLTK or if
#  (b) find_package can't find your installation directory because
# you installed FLTK in a non-standard location.  It points to
#  (a) the base folder of the build directory, or
#  (b) <fltk-install-prefix>/share/fltk
# resp., where <fltk-install-prefix> is the installation prefix you
# used to install FLTK.
# (The file FLTKConfig.cmake and others must be found in that path.)

set(FLTK_DIR /git/fltk/master/build/debug CACHE STRING 
    "FLTK binary folder with FLTKConfig.cmake")

find_package(FLTK REQUIRED CONFIG)

add_executable(hello WIN32 MACOSX_BUNDLE ../src/hello.cxx)
if (APPLE)
  target_link_libraries(hello "-framework cocoa")
endif (APPLE)

target_include_directories(hello PRIVATE ${FLTK_INCLUDE_DIRS})

target_link_libraries(hello fltk)

# Debug ...

message(STATUS "BUILD_FLTK                  = ${BUILD_FLTK}")
message(STATUS "FLTK_DIR                    = ${FLTK_DIR}")
message(STATUS "FLTK_FOUND                  = ${FLTK_FOUND}")
message(STATUS "FLTK_COMMIT                 = '${FLTK_COMMIT}'")
message(STATUS "FLTK_INCLUDE_DIRS           = ${FLTK_INCLUDE_DIRS}")

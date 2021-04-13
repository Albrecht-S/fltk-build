Example FLTK build projects

FLTK: https://www.fltk.org/
      https://github.com/fltk/fltk

Each CMakeLists.txt file in this project constitutes a separate project
which can be built with FLTK. The single source file in the src/ folder
is shared among all build configurations. The resultant "hello world"
program shows the FLTK version number.

Currently there are three build directories:

1. cmake-external-project:

The CMakeLists.txt file in this directory uses the CMake module
ExternalProject and the CMake function ExternalProject_Add() to
download and build FLTK.

2. cmake-fetch-content:

The CMakeLists.txt file in this directory uses the CMake module
FetchContent and the CMake functions FetchContent_Declare() and
FetchContent_MakeAvailable() to download and build FLTK.

3. cmake-simple:

The CMakeLists.txt file in this directory uses standard CMake
functions as described in <FLTK>/README.CMake.txt to build the
program. This requires a pre-built FLTK installation.


Note: these CMake build files are intended as working examples to
build applications with FLTK - as of the date they were written.
Changes are likely and I will try to update the examples when needed.

I will accept GitHub Issue reports and/or PR's only if I think they
are useful for a general case. Feel free to try if you have some
suggestions.

Future work may include more complicated examples with different
FLTK libraries and/or linking shared libraries.

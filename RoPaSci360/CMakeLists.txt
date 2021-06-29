# CMakeList.txt : CMake project for RoPaSci360, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (RoPaSci360 "RoPaSci360.cpp" "RoPaSci360.h"  "components.h" "utils.h" "utils.cpp" "components.h" "components.cpp")

# TODO: Add tests and install targets if needed.

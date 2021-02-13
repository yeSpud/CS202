cmake_minimum_required(VERSION 3.17)
project(HW1)

set(CMAKE_CXX_STANDARD 17)

add_executable(TimeIt StopWatch.cpp StopWatch.hpp TimeIt.cpp)
add_executable(TimeItII StopWatch.cpp StopWatch.hpp TimeItII.cpp)
add_executable(c_style_strings c_style_strings.cpp)
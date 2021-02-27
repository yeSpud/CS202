cmake_minimum_required(VERSION 3.17)
project(HW3)

set(CMAKE_CXX_STANDARD 17)

add_executable(tokenizer tokenizer.cpp Money.cpp Money.hpp)
add_executable(money Money.cpp Money.hpp moneytest.cpp catch.hpp)
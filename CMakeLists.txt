cmake_minimum_required(VERSION 3.24)
project(functional_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(functional_cpp main.cpp components/Iterator.h components/Map.h)

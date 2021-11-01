cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 11)

project(loader)

find_package(Boost COMPONENTS program_options REQUIRED)
find_package(Catch2 REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
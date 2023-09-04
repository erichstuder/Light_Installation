cmake_minimum_required(VERSION 3.18.4)

project(Tutorial VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(simulator simulator.cpp)

target_include_directories(simulator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/gnuplot-iostream/")

target_link_libraries(simulator boost_iostreams boost_system boost_filesystem)

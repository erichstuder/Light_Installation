cmake_minimum_required(VERSION 3.18.4)

project(Tutorial VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable generation of compile_commands.json
# This file is then used by IntelliSense, see: .vscode/c_cpp_properties.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(simulator simulator.cpp)

target_include_directories(simulator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/gnuplot-iostream/")
target_include_directories(simulator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/lib/LedPatterns/")

target_link_libraries(simulator boost_iostreams boost_system boost_filesystem)

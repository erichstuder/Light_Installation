cmake_minimum_required(VERSION 3.18.4)

project(simulator VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(GTest::GTest UNKNOWN IMPORTED)

add_library(simulator_lib STATIC ../simulator.cpp)
target_include_directories(simulator_lib PRIVATE "../gnuplot-iostream/")
target_include_directories(simulator_lib PRIVATE "../../firmware/lib/LedPatterns/")

add_executable(simulator_steps step_definitions/StepDefinitionRunner.cpp)
target_link_libraries(simulator_steps PRIVATE simulator_lib /lib/libcucumber-cpp.a GTest::GTest)

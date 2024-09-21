cmake_minimum_required(VERSION 3.18.4)

project(simulator VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(CUCUMBER)

add_library(simulator_lib STATIC ../src/simulator.cpp)
target_sources(simulator_lib PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../Shared/software/firmware/lib/LedPatterns/Wave.cpp")
target_include_directories(simulator_lib PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../src/gnuplot-iostream/")
target_include_directories(simulator_lib PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../Shared/software/firmware/lib/LedPatterns/")
target_link_libraries(simulator_lib boost_iostreams boost_system boost_filesystem) #TODO: necessary?

add_executable(simulator_steps "step_definitions/Start_Simulator__steps.cpp")
target_include_directories(simulator_steps PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../Shared/software/firmware/lib/LedPatterns/")
target_include_directories(simulator_steps PRIVATE "/usr/src/cucumber-cpp/build/gmock/src/gmock/googletest/include")
target_include_directories(simulator_steps PRIVATE "/usr/src/cucumber-cpp/include")
target_include_directories(simulator_steps PRIVATE "/usr/src/cucumber-cpp/build/src")
target_include_directories(simulator_steps PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../src")
target_link_libraries(simulator_steps PRIVATE
    simulator_lib
    "/lib/libcucumber-cpp.a"
    "/usr/src/cucumber-cpp/build/gmock/src/gmock-build/lib/libgtest.a"
    "/usr/src/cucumber-cpp/build/gmock/src/gmock-build/lib/libgmock.a"
    boost_iostreams boost_system boost_filesystem boost_regex boost_program_options
)

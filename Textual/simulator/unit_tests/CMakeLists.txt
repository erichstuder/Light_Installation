cmake_minimum_required(VERSION 3.10)
project(simulator_unit_tests)

add_subdirectory(/usr/googletest /usr/googletest/build)
include_directories(/usr/googletest/googletest/include)
include_directories(/usr/googletest/googlemock/include)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
endif()

add_executable(unit_tests main.cpp)

target_link_libraries(unit_tests gtest gtest_main gmock gmock_main)

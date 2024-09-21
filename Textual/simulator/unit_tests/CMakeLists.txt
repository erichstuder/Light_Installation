cmake_minimum_required(VERSION 3.10)
project(simulator_unit_tests)

add_subdirectory(/usr/googletest /usr/googletest/build)
include_directories(
    /usr/googletest/googletest/include
    /usr/googletest/googlemock/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/gnuplot-iostream
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../Shared/software/firmware/lib/LedPatterns
)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
endif()

add_compile_definitions(UNIT_TEST)

add_executable(unit_tests main.cpp)

file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
target_sources(unit_tests PRIVATE ${TEST_SOURCES})

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp")
target_sources(unit_tests PRIVATE ${SOURCES})

file(GLOB LED_PATTERNS "${CMAKE_CURRENT_SOURCE_DIR}/../../../Shared/software/firmware/lib/LedPatterns/*.cpp")
target_sources(unit_tests PRIVATE ${LED_PATTERNS})

target_link_libraries(
    unit_tests gtest
    gtest_main gmock gmock_main boost_iostreams
    boost_system boost_filesystem
)

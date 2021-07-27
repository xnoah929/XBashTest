cmake_minimum_required(VERSION 3.11)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

#"mocks/*.cpp",
file(GLOB UNIT_TEST_SOURCES
    "*.cpp"
)
set(This XBash_test)
project(${This} C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS "-coverage -lgcov")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

enable_testing()

include_directories(
    "../src/Commands"
    "../src/Commands/Command"
    "../src/Help"
    )

add_executable(${This} ${UNIT_TEST_SOURCES})

target_link_libraries(${This} PUBLIC
    gtest_main
    gmock_main
    gtest
    gmock
    pthread
    commands.lib
    command.lib
)
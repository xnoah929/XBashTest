cmake_minimum_required(VERSION 3.11)
project(XBash VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
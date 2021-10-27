cmake_minimum_required(VERSION 3.5)
project(binary_search)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cc)

add_executable(binary_search ${SOURCE_FILES} ${HEADER_FILES})

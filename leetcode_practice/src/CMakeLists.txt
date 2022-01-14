cmake_minimum_required(VERSION 3.5)
project(solutions_lib)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(HEADER_FILES solutions.h
                    )

set(SOURCE_FILES solutions.cc
                    )

add_library(solutions_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

cmake_minimum_required(VERSION 3.5)

project(GARPH_LIB VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_path(GARPH_INCLUDE_DIRS graph.h graph_directed.h graph_representation.h HINTS ${CMAKE_SOURCE_DIR}/include)

add_library(graph SHARED graph.cc graph_directed.cc graph_representation.cc)
target_include_directories(graph PUBLIC ${GARPH_INCLUDE_DIRS})

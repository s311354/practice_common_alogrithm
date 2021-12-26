cmake_minimum_required(VERSION 3.5)
project(graphs_lib)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(HEADER_FILES    graph.h
                    graph_directed.h
                    graph_representation.h
    )

set(SOURCE_FILES    graph.cc 
                    graph_directed.cc 
                    graph_representation.cc)

add_library(graphs_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

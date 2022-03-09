cmake_minimum_required(VERSION 3.5)

project(GRAPH_EXAMPLE_AREA VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_path(GRAPH_INCLUDE_DIRS graph.h graph_directed.h  graph_representation.h HINTS ${CMAKE_SOURCE_DIR}/include)

message(${GRAPH_INCLUDE_DIRS})

add_executable(folder_structure main.cc)
target_include_directories(folder_structure PUBLIC ${GRAPH_INCLUDE_DIRS})
target_link_libraries(folder_structure graph)

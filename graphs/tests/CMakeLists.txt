cmake_minimum_required(VERSION 3.5)
project(graphs_unit_test_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")
set(linkedlist_SOURCE_DIR ${PROJECT_BINARY_DIR})

add_subdirectory(${PROJECT_BINARY_DIR}/bin/googletest-src)
add_subdirectory(src)

set(SOURCE_FILES graphs_unit_test.cc)
add_executable(graphs_unit_test ${SOURCE_FILES})

target_link_libraries(graphs_unit_test graphs_lib)
target_link_libraries(graphs_unit_test gtest gtest_main)

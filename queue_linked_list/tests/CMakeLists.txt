cmake_minimum_required(VERSION 3.5)
project(queue_linked_list_unit_test_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(linkedlist_SOURCE_DIR ${PROJECT_BINARY_DIR})

add_subdirectory(${PROJECT_BINARY_DIR}/bin/gtest-src)
add_subdirectory(src)
include_directories(${gtest_SOURCE_DIR}/include
                    ${gtest_SOURCE_DIR})

set(SOURCE_FILES queue_linked_list_unit_test.cc)
add_executable(queue_linked_list_unit_test ${SOURCE_FILES})

target_link_libraries(queue_linked_list_unit_test queue_linked_list_lib)
target_link_libraries(queue_linked_list_unit_test gtest gtest_main)

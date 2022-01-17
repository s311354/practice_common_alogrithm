cmake_minimum_required(VERSION 3.5)
project(leetcode_unit_test_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

add_subdirectory(lib/googletest)
add_subdirectory(src)
include_directories(${gtest_SOURCE_DIR}/include
                    ${gtest_SOURCE_DIR})

set(SOURCE_FILES leetcode_unit_test.cc)
add_executable(leetcode_unit_test ${SOURCE_FILES})

target_link_libraries(leetcode_unit_test solutions_lib)
target_link_libraries(leetcode_unit_test gtest gtest_main)

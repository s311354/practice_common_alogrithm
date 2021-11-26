cmake_minimum_required(VERSION 3.5)
project(hash_table_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cc hash_table_tests.cc hash_table.cc)
add_executable(hash_table ${SOURCE_FILES} ${HEADER_FILES})

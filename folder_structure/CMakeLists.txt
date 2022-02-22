cmake_minimum_required(VERSION 3.5)
project(folder_structure_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

include_directories(src)
add_subdirectory(src)

set(SOURCE_FILES main.cc)
add_executable(folder_structure ${SOURCE_FILES})

target_link_libraries(folder_structure graphs_lib)

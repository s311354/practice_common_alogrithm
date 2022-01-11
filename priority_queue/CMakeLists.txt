cmake_minimum_required(VERSION 3.5)
project(priority_queue_proj)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

#include_directories(src)
#add_subdirectory(src)

set(SOURCE_FILES main.cc 
                 priority_queue.cc)

add_executable(priority_queue ${SOURCE_FILES})

#target_link_libraries(priority_queue priority_queue_lib)

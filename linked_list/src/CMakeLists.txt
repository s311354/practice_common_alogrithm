cmake_minimum_required(VERSION 3.5)
project(linkedlists_lib)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(HEADER_FILES    linked_list.h
                    list_element.h
                    )

set(SOURCE_FILES    linked_list.cc
                    list_element.cc
                    )

add_library(linkedlists_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

cmake_minimum_required(VERSION 3.5)

include(ExternalProject)
ExternalProject_Add(googletest
  URL https://src.fedoraproject.org/repo/pkgs/gtest/gtest-1.7.0.zip/2d6ec8ccdf5c46b05ba54a9fd1d130d7/gtest-1.7.0.zip
  URL_HASH SHA1=f85f6d2481e2c6c4a18539e391aa4ea8ab0394af
  SOURCE_DIR "bin/gtest-src"
  BINARY_DIR "bin/gtest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)


add_subdirectory(binary_search)
add_subdirectory(graphs)
add_subdirectory(hash_table)
add_subdirectory(array)
add_subdirectory(design_pattern)
add_subdirectory(linked_list)
add_subdirectory(priority_queue)
add_subdirectory(queue_linked_list)

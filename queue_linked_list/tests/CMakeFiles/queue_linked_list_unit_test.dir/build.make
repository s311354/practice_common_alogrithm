# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.6/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests

# Include any dependencies generated for this target.
include CMakeFiles/queue_linked_list_unit_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/queue_linked_list_unit_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queue_linked_list_unit_test.dir/flags.make

CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.o: CMakeFiles/queue_linked_list_unit_test.dir/flags.make
CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.o: queue_linked_list_unit_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.o -c /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests/queue_linked_list_unit_test.cc

CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests/queue_linked_list_unit_test.cc > CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.i

CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests/queue_linked_list_unit_test.cc -o CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.s

# Object files for target queue_linked_list_unit_test
queue_linked_list_unit_test_OBJECTS = \
"CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.o"

# External object files for target queue_linked_list_unit_test
queue_linked_list_unit_test_EXTERNAL_OBJECTS =

queue_linked_list_unit_test: CMakeFiles/queue_linked_list_unit_test.dir/queue_linked_list_unit_test.cc.o
queue_linked_list_unit_test: CMakeFiles/queue_linked_list_unit_test.dir/build.make
queue_linked_list_unit_test: src/libqueue_linked_list_lib.a
queue_linked_list_unit_test: bin/gtest-src/libgtest.a
queue_linked_list_unit_test: bin/gtest-src/libgtest_main.a
queue_linked_list_unit_test: bin/gtest-src/libgtest.a
queue_linked_list_unit_test: CMakeFiles/queue_linked_list_unit_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable queue_linked_list_unit_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queue_linked_list_unit_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queue_linked_list_unit_test.dir/build: queue_linked_list_unit_test

.PHONY : CMakeFiles/queue_linked_list_unit_test.dir/build

CMakeFiles/queue_linked_list_unit_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/queue_linked_list_unit_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/queue_linked_list_unit_test.dir/clean

CMakeFiles/queue_linked_list_unit_test.dir/depend:
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/tests/CMakeFiles/queue_linked_list_unit_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queue_linked_list_unit_test.dir/depend


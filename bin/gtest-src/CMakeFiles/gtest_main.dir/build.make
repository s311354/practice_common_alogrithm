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
CMAKE_SOURCE_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests

# Include any dependencies generated for this target.
include bin/gtest-src/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include bin/gtest-src/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include bin/gtest-src/CMakeFiles/gtest_main.dir/flags.make

bin/gtest-src/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: bin/gtest-src/CMakeFiles/gtest_main.dir/flags.make
bin/gtest-src/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: bin/gtest-src/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/gtest-src/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src/src/gtest_main.cc

bin/gtest-src/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

bin/gtest-src/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

bin/gtest-src/libgtest_main.a: bin/gtest-src/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
bin/gtest-src/libgtest_main.a: bin/gtest-src/CMakeFiles/gtest_main.dir/build.make
bin/gtest-src/libgtest_main.a: bin/gtest-src/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/gtest-src/CMakeFiles/gtest_main.dir/build: bin/gtest-src/libgtest_main.a

.PHONY : bin/gtest-src/CMakeFiles/gtest_main.dir/build

bin/gtest-src/CMakeFiles/gtest_main.dir/clean:
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : bin/gtest-src/CMakeFiles/gtest_main.dir/clean

bin/gtest-src/CMakeFiles/gtest_main.dir/depend:
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/leetcode_practice/tests/bin/gtest-src/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/gtest-src/CMakeFiles/gtest_main.dir/depend


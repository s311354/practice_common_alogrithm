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
CMAKE_SOURCE_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list

# Utility rule file for googletest.

# Include the progress variables for this target.
include CMakeFiles/googletest.dir/progress.make

CMakeFiles/googletest: CMakeFiles/googletest-complete


CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-install
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-mkdir
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-download
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-update
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-patch
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-configure
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-build
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-install
CMakeFiles/googletest-complete: googletest-prefix/src/googletest-stamp/googletest-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'googletest'"
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles/googletest-complete
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-done

googletest-prefix/src/googletest-stamp/googletest-install: googletest-prefix/src/googletest-stamp/googletest-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'googletest'"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-install

googletest-prefix/src/googletest-stamp/googletest-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'googletest'"
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-src
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/tmp
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-mkdir

googletest-prefix/src/googletest-stamp/googletest-download: googletest-prefix/src/googletest-stamp/googletest-urlinfo.txt
googletest-prefix/src/googletest-stamp/googletest-download: googletest-prefix/src/googletest-stamp/googletest-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'googletest'"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR && /usr/local/Cellar/cmake/3.19.6/bin/cmake -P /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/download-googletest.cmake
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR && /usr/local/Cellar/cmake/3.19.6/bin/cmake -P /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/verify-googletest.cmake
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR && /usr/local/Cellar/cmake/3.19.6/bin/cmake -P /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/extract-googletest.cmake
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-download

googletest-prefix/src/googletest-stamp/googletest-update: googletest-prefix/src/googletest-stamp/googletest-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'googletest'"
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-update

googletest-prefix/src/googletest-stamp/googletest-patch: googletest-prefix/src/googletest-stamp/googletest-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'googletest'"
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-patch

googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/tmp/googletest-cfgcmd.txt
googletest-prefix/src/googletest-stamp/googletest-configure: googletest-prefix/src/googletest-stamp/googletest-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'googletest'"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-configure

googletest-prefix/src/googletest-stamp/googletest-build: googletest-prefix/src/googletest-stamp/googletest-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'googletest'"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-build

googletest-prefix/src/googletest-stamp/googletest-test: googletest-prefix/src/googletest-stamp/googletest-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'googletest'"
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMAKE_BINARY_DIR/gtest-build && /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/googletest-prefix/src/googletest-stamp/googletest-test

googletest: CMakeFiles/googletest
googletest: CMakeFiles/googletest-complete
googletest: googletest-prefix/src/googletest-stamp/googletest-build
googletest: googletest-prefix/src/googletest-stamp/googletest-configure
googletest: googletest-prefix/src/googletest-stamp/googletest-download
googletest: googletest-prefix/src/googletest-stamp/googletest-install
googletest: googletest-prefix/src/googletest-stamp/googletest-mkdir
googletest: googletest-prefix/src/googletest-stamp/googletest-patch
googletest: googletest-prefix/src/googletest-stamp/googletest-test
googletest: googletest-prefix/src/googletest-stamp/googletest-update
googletest: CMakeFiles/googletest.dir/build.make

.PHONY : googletest

# Rule to build all files generated by this target.
CMakeFiles/googletest.dir/build: googletest

.PHONY : CMakeFiles/googletest.dir/build

CMakeFiles/googletest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/googletest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/googletest.dir/clean

CMakeFiles/googletest.dir/depend:
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/queue_linked_list/CMakeFiles/googletest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/googletest.dir/depend


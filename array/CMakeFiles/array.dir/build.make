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
CMAKE_SOURCE_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array

# Include any dependencies generated for this target.
include CMakeFiles/array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/array.dir/flags.make

CMakeFiles/array.dir/main.cc.o: CMakeFiles/array.dir/flags.make
CMakeFiles/array.dir/main.cc.o: main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/array.dir/main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/array.dir/main.cc.o -c /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/main.cc

CMakeFiles/array.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/array.dir/main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/main.cc > CMakeFiles/array.dir/main.cc.i

CMakeFiles/array.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/array.dir/main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/main.cc -o CMakeFiles/array.dir/main.cc.s

CMakeFiles/array.dir/jvector.cc.o: CMakeFiles/array.dir/flags.make
CMakeFiles/array.dir/jvector.cc.o: jvector.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/array.dir/jvector.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/array.dir/jvector.cc.o -c /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/jvector.cc

CMakeFiles/array.dir/jvector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/array.dir/jvector.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/jvector.cc > CMakeFiles/array.dir/jvector.cc.i

CMakeFiles/array.dir/jvector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/array.dir/jvector.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/jvector.cc -o CMakeFiles/array.dir/jvector.cc.s

CMakeFiles/array.dir/jvector_test.cc.o: CMakeFiles/array.dir/flags.make
CMakeFiles/array.dir/jvector_test.cc.o: jvector_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/array.dir/jvector_test.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/array.dir/jvector_test.cc.o -c /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/jvector_test.cc

CMakeFiles/array.dir/jvector_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/array.dir/jvector_test.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/jvector_test.cc > CMakeFiles/array.dir/jvector_test.cc.i

CMakeFiles/array.dir/jvector_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/array.dir/jvector_test.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/jvector_test.cc -o CMakeFiles/array.dir/jvector_test.cc.s

# Object files for target array
array_OBJECTS = \
"CMakeFiles/array.dir/main.cc.o" \
"CMakeFiles/array.dir/jvector.cc.o" \
"CMakeFiles/array.dir/jvector_test.cc.o"

# External object files for target array
array_EXTERNAL_OBJECTS =

array: CMakeFiles/array.dir/main.cc.o
array: CMakeFiles/array.dir/jvector.cc.o
array: CMakeFiles/array.dir/jvector_test.cc.o
array: CMakeFiles/array.dir/build.make
array: CMakeFiles/array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/array.dir/build: array

.PHONY : CMakeFiles/array.dir/build

CMakeFiles/array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/array.dir/clean

CMakeFiles/array.dir/depend:
	cd /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array /Users/shi-rongliu/Documents/GitHub/cplusplus_practice-/practice_common_alogrithm/array/CMakeFiles/array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/array.dir/depend


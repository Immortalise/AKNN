# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/triste/Desktop/AKNN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/triste/Desktop/AKNN/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AKNN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AKNN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AKNN.dir/flags.make

CMakeFiles/AKNN.dir/main.cpp.o: CMakeFiles/AKNN.dir/flags.make
CMakeFiles/AKNN.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triste/Desktop/AKNN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AKNN.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AKNN.dir/main.cpp.o -c /Users/triste/Desktop/AKNN/main.cpp

CMakeFiles/AKNN.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AKNN.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/triste/Desktop/AKNN/main.cpp > CMakeFiles/AKNN.dir/main.cpp.i

CMakeFiles/AKNN.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AKNN.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/triste/Desktop/AKNN/main.cpp -o CMakeFiles/AKNN.dir/main.cpp.s

CMakeFiles/AKNN.dir/source/load.cpp.o: CMakeFiles/AKNN.dir/flags.make
CMakeFiles/AKNN.dir/source/load.cpp.o: ../source/load.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triste/Desktop/AKNN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AKNN.dir/source/load.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AKNN.dir/source/load.cpp.o -c /Users/triste/Desktop/AKNN/source/load.cpp

CMakeFiles/AKNN.dir/source/load.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AKNN.dir/source/load.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/triste/Desktop/AKNN/source/load.cpp > CMakeFiles/AKNN.dir/source/load.cpp.i

CMakeFiles/AKNN.dir/source/load.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AKNN.dir/source/load.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/triste/Desktop/AKNN/source/load.cpp -o CMakeFiles/AKNN.dir/source/load.cpp.s

CMakeFiles/AKNN.dir/source/AKNN.cpp.o: CMakeFiles/AKNN.dir/flags.make
CMakeFiles/AKNN.dir/source/AKNN.cpp.o: ../source/AKNN.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triste/Desktop/AKNN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AKNN.dir/source/AKNN.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AKNN.dir/source/AKNN.cpp.o -c /Users/triste/Desktop/AKNN/source/AKNN.cpp

CMakeFiles/AKNN.dir/source/AKNN.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AKNN.dir/source/AKNN.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/triste/Desktop/AKNN/source/AKNN.cpp > CMakeFiles/AKNN.dir/source/AKNN.cpp.i

CMakeFiles/AKNN.dir/source/AKNN.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AKNN.dir/source/AKNN.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/triste/Desktop/AKNN/source/AKNN.cpp -o CMakeFiles/AKNN.dir/source/AKNN.cpp.s

CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.o: CMakeFiles/AKNN.dir/flags.make
CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.o: ../source/AKNN_with_mmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triste/Desktop/AKNN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.o -c /Users/triste/Desktop/AKNN/source/AKNN_with_mmap.cpp

CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/triste/Desktop/AKNN/source/AKNN_with_mmap.cpp > CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.i

CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/triste/Desktop/AKNN/source/AKNN_with_mmap.cpp -o CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.s

# Object files for target AKNN
AKNN_OBJECTS = \
"CMakeFiles/AKNN.dir/main.cpp.o" \
"CMakeFiles/AKNN.dir/source/load.cpp.o" \
"CMakeFiles/AKNN.dir/source/AKNN.cpp.o" \
"CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.o"

# External object files for target AKNN
AKNN_EXTERNAL_OBJECTS =

AKNN: CMakeFiles/AKNN.dir/main.cpp.o
AKNN: CMakeFiles/AKNN.dir/source/load.cpp.o
AKNN: CMakeFiles/AKNN.dir/source/AKNN.cpp.o
AKNN: CMakeFiles/AKNN.dir/source/AKNN_with_mmap.cpp.o
AKNN: CMakeFiles/AKNN.dir/build.make
AKNN: CMakeFiles/AKNN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/triste/Desktop/AKNN/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable AKNN"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AKNN.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AKNN.dir/build: AKNN

.PHONY : CMakeFiles/AKNN.dir/build

CMakeFiles/AKNN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AKNN.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AKNN.dir/clean

CMakeFiles/AKNN.dir/depend:
	cd /Users/triste/Desktop/AKNN/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/triste/Desktop/AKNN /Users/triste/Desktop/AKNN /Users/triste/Desktop/AKNN/cmake-build-debug /Users/triste/Desktop/AKNN/cmake-build-debug /Users/triste/Desktop/AKNN/cmake-build-debug/CMakeFiles/AKNN.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AKNN.dir/depend


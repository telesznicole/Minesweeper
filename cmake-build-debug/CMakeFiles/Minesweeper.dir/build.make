# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nicoletelesz/CLionProjects/Project3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nicoletelesz/CLionProjects/Project3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Minesweeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Minesweeper.dir/flags.make

CMakeFiles/Minesweeper.dir/main.cpp.o: CMakeFiles/Minesweeper.dir/flags.make
CMakeFiles/Minesweeper.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicoletelesz/CLionProjects/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Minesweeper.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Minesweeper.dir/main.cpp.o -c /Users/nicoletelesz/CLionProjects/Project3/main.cpp

CMakeFiles/Minesweeper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Minesweeper.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicoletelesz/CLionProjects/Project3/main.cpp > CMakeFiles/Minesweeper.dir/main.cpp.i

CMakeFiles/Minesweeper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Minesweeper.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicoletelesz/CLionProjects/Project3/main.cpp -o CMakeFiles/Minesweeper.dir/main.cpp.s

# Object files for target Minesweeper
Minesweeper_OBJECTS = \
"CMakeFiles/Minesweeper.dir/main.cpp.o"

# External object files for target Minesweeper
Minesweeper_EXTERNAL_OBJECTS =

Minesweeper: CMakeFiles/Minesweeper.dir/main.cpp.o
Minesweeper: CMakeFiles/Minesweeper.dir/build.make
Minesweeper: /usr/local/lib/libsfml-graphics.2.5.1.dylib
Minesweeper: /usr/local/lib/libsfml-audio.2.5.1.dylib
Minesweeper: /usr/local/lib/libsfml-window.2.5.1.dylib
Minesweeper: /usr/local/lib/libsfml-system.2.5.1.dylib
Minesweeper: CMakeFiles/Minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nicoletelesz/CLionProjects/Project3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Minesweeper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Minesweeper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Minesweeper.dir/build: Minesweeper

.PHONY : CMakeFiles/Minesweeper.dir/build

CMakeFiles/Minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Minesweeper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Minesweeper.dir/clean

CMakeFiles/Minesweeper.dir/depend:
	cd /Users/nicoletelesz/CLionProjects/Project3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nicoletelesz/CLionProjects/Project3 /Users/nicoletelesz/CLionProjects/Project3 /Users/nicoletelesz/CLionProjects/Project3/cmake-build-debug /Users/nicoletelesz/CLionProjects/Project3/cmake-build-debug /Users/nicoletelesz/CLionProjects/Project3/cmake-build-debug/CMakeFiles/Minesweeper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Minesweeper.dir/depend


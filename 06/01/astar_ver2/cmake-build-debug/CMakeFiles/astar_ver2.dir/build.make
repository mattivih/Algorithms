# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/astar_ver2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/astar_ver2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/astar_ver2.dir/flags.make

CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o: CMakeFiles/astar_ver2.dir/flags.make
CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o: /Users/Matti/Desktop/Sith\ Empire/PELISOVELLUKSET/Peliohjelmointi\ ja\ tekoälyt/Tehtävät/06/01/astar_ver2/astar/test_astar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o -c "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/astar/test_astar.cpp"

CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/astar/test_astar.cpp" > CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.i

CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/astar/test_astar.cpp" -o CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.s

CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.requires:

.PHONY : CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.requires

CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.provides: CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.requires
	$(MAKE) -f CMakeFiles/astar_ver2.dir/build.make CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.provides.build
.PHONY : CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.provides

CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.provides.build: CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o


# Object files for target astar_ver2
astar_ver2_OBJECTS = \
"CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o"

# External object files for target astar_ver2
astar_ver2_EXTERNAL_OBJECTS =

astar_ver2: CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o
astar_ver2: CMakeFiles/astar_ver2.dir/build.make
astar_ver2: CMakeFiles/astar_ver2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable astar_ver2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/astar_ver2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/astar_ver2.dir/build: astar_ver2

.PHONY : CMakeFiles/astar_ver2.dir/build

CMakeFiles/astar_ver2.dir/requires: CMakeFiles/astar_ver2.dir/astar/test_astar.cpp.o.requires

.PHONY : CMakeFiles/astar_ver2.dir/requires

CMakeFiles/astar_ver2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/astar_ver2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/astar_ver2.dir/clean

CMakeFiles/astar_ver2.dir/depend:
	cd "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2" "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2" "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/cmake-build-debug" "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/cmake-build-debug" "/Users/Matti/Desktop/Sith Empire/PELISOVELLUKSET/Peliohjelmointi ja tekoälyt/Tehtävät/06/01/astar_ver2/cmake-build-debug/CMakeFiles/astar_ver2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/astar_ver2.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/build"

# Include any dependencies generated for this target.
include CMakeFiles/runMain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runMain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runMain.dir/flags.make

CMakeFiles/runMain.dir/main.cpp.o: CMakeFiles/runMain.dir/flags.make
CMakeFiles/runMain.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runMain.dir/main.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runMain.dir/main.cpp.o -c "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/main.cpp"

CMakeFiles/runMain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runMain.dir/main.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/main.cpp" > CMakeFiles/runMain.dir/main.cpp.i

CMakeFiles/runMain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runMain.dir/main.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/main.cpp" -o CMakeFiles/runMain.dir/main.cpp.s

CMakeFiles/runMain.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/runMain.dir/main.cpp.o.requires

CMakeFiles/runMain.dir/main.cpp.o.provides: CMakeFiles/runMain.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/runMain.dir/build.make CMakeFiles/runMain.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/runMain.dir/main.cpp.o.provides

CMakeFiles/runMain.dir/main.cpp.o.provides.build: CMakeFiles/runMain.dir/main.cpp.o


# Object files for target runMain
runMain_OBJECTS = \
"CMakeFiles/runMain.dir/main.cpp.o"

# External object files for target runMain
runMain_EXTERNAL_OBJECTS =

runMain: CMakeFiles/runMain.dir/main.cpp.o
runMain: CMakeFiles/runMain.dir/build.make
runMain: libapplibrary.a
runMain: CMakeFiles/runMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runMain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runMain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runMain.dir/build: runMain

.PHONY : CMakeFiles/runMain.dir/build

CMakeFiles/runMain.dir/requires: CMakeFiles/runMain.dir/main.cpp.o.requires

.PHONY : CMakeFiles/runMain.dir/requires

CMakeFiles/runMain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runMain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runMain.dir/clean

CMakeFiles/runMain.dir/depend:
	cd "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/build" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/build" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab02-copy/build/CMakeFiles/runMain.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/runMain.dir/depend


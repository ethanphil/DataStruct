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
CMAKE_SOURCE_DIR = "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/build"

# Include any dependencies generated for this target.
include CMakeFiles/applibrary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/applibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/applibrary.dir/flags.make

CMakeFiles/applibrary.dir/SomeThing.cpp.o: CMakeFiles/applibrary.dir/flags.make
CMakeFiles/applibrary.dir/SomeThing.cpp.o: ../SomeThing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/applibrary.dir/SomeThing.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/applibrary.dir/SomeThing.cpp.o -c "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/SomeThing.cpp"

CMakeFiles/applibrary.dir/SomeThing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/applibrary.dir/SomeThing.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/SomeThing.cpp" > CMakeFiles/applibrary.dir/SomeThing.cpp.i

CMakeFiles/applibrary.dir/SomeThing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/applibrary.dir/SomeThing.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/SomeThing.cpp" -o CMakeFiles/applibrary.dir/SomeThing.cpp.s

CMakeFiles/applibrary.dir/SomeThing.cpp.o.requires:

.PHONY : CMakeFiles/applibrary.dir/SomeThing.cpp.o.requires

CMakeFiles/applibrary.dir/SomeThing.cpp.o.provides: CMakeFiles/applibrary.dir/SomeThing.cpp.o.requires
	$(MAKE) -f CMakeFiles/applibrary.dir/build.make CMakeFiles/applibrary.dir/SomeThing.cpp.o.provides.build
.PHONY : CMakeFiles/applibrary.dir/SomeThing.cpp.o.provides

CMakeFiles/applibrary.dir/SomeThing.cpp.o.provides.build: CMakeFiles/applibrary.dir/SomeThing.cpp.o


# Object files for target applibrary
applibrary_OBJECTS = \
"CMakeFiles/applibrary.dir/SomeThing.cpp.o"

# External object files for target applibrary
applibrary_EXTERNAL_OBJECTS =

libapplibrary.a: CMakeFiles/applibrary.dir/SomeThing.cpp.o
libapplibrary.a: CMakeFiles/applibrary.dir/build.make
libapplibrary.a: CMakeFiles/applibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libapplibrary.a"
	$(CMAKE_COMMAND) -P CMakeFiles/applibrary.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/applibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/applibrary.dir/build: libapplibrary.a

.PHONY : CMakeFiles/applibrary.dir/build

CMakeFiles/applibrary.dir/requires: CMakeFiles/applibrary.dir/SomeThing.cpp.o.requires

.PHONY : CMakeFiles/applibrary.dir/requires

CMakeFiles/applibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/applibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/applibrary.dir/clean

CMakeFiles/applibrary.dir/depend:
	cd "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/build" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/build" "/mnt/c/Users/ethan/OneDrive/Documents/School Fall 2021/DataStruct/Lab03/build/CMakeFiles/applibrary.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/applibrary.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\1\untitled\jixiebi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\1\untitled\jixiebi\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/jixiebi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jixiebi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jixiebi.dir/flags.make

CMakeFiles/jixiebi.dir/main.cpp.obj: CMakeFiles/jixiebi.dir/flags.make
CMakeFiles/jixiebi.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\1\untitled\jixiebi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/jixiebi.dir/main.cpp.obj"
	C:\ming64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\jixiebi.dir\main.cpp.obj -c D:\code\1\untitled\jixiebi\main.cpp

CMakeFiles/jixiebi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jixiebi.dir/main.cpp.i"
	C:\ming64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\1\untitled\jixiebi\main.cpp > CMakeFiles\jixiebi.dir\main.cpp.i

CMakeFiles/jixiebi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jixiebi.dir/main.cpp.s"
	C:\ming64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\1\untitled\jixiebi\main.cpp -o CMakeFiles\jixiebi.dir\main.cpp.s

# Object files for target jixiebi
jixiebi_OBJECTS = \
"CMakeFiles/jixiebi.dir/main.cpp.obj"

# External object files for target jixiebi
jixiebi_EXTERNAL_OBJECTS =

jixiebi.exe: CMakeFiles/jixiebi.dir/main.cpp.obj
jixiebi.exe: CMakeFiles/jixiebi.dir/build.make
jixiebi.exe: CMakeFiles/jixiebi.dir/linklibs.rsp
jixiebi.exe: CMakeFiles/jixiebi.dir/objects1.rsp
jixiebi.exe: CMakeFiles/jixiebi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\1\untitled\jixiebi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable jixiebi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\jixiebi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jixiebi.dir/build: jixiebi.exe

.PHONY : CMakeFiles/jixiebi.dir/build

CMakeFiles/jixiebi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\jixiebi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/jixiebi.dir/clean

CMakeFiles/jixiebi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\1\untitled\jixiebi D:\code\1\untitled\jixiebi D:\code\1\untitled\jixiebi\cmake-build-debug D:\code\1\untitled\jixiebi\cmake-build-debug D:\code\1\untitled\jixiebi\cmake-build-debug\CMakeFiles\jixiebi.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jixiebi.dir/depend

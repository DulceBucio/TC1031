# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BT.dir/flags.make

CMakeFiles/BT.dir/main.cpp.obj: CMakeFiles/BT.dir/flags.make
CMakeFiles/BT.dir/main.cpp.obj: CMakeFiles/BT.dir/includes_CXX.rsp
CMakeFiles/BT.dir/main.cpp.obj: ../main.cpp
CMakeFiles/BT.dir/main.cpp.obj: CMakeFiles/BT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BT.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BT.dir/main.cpp.obj -MF CMakeFiles\BT.dir\main.cpp.obj.d -o CMakeFiles\BT.dir\main.cpp.obj -c C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\main.cpp

CMakeFiles/BT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BT.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\main.cpp > CMakeFiles\BT.dir\main.cpp.i

CMakeFiles/BT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BT.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\main.cpp -o CMakeFiles\BT.dir\main.cpp.s

# Object files for target BT
BT_OBJECTS = \
"CMakeFiles/BT.dir/main.cpp.obj"

# External object files for target BT
BT_EXTERNAL_OBJECTS =

BT.exe: CMakeFiles/BT.dir/main.cpp.obj
BT.exe: CMakeFiles/BT.dir/build.make
BT.exe: CMakeFiles/BT.dir/linklibs.rsp
BT.exe: CMakeFiles/BT.dir/objects1.rsp
BT.exe: CMakeFiles/BT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BT.dir/build: BT.exe
.PHONY : CMakeFiles/BT.dir/build

CMakeFiles/BT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BT.dir/clean

CMakeFiles/BT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\cmake-build-debug C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\cmake-build-debug C:\Users\yasmi\OneDrive\Documents\3ero\TC1031\TC1031\BT\cmake-build-debug\CMakeFiles\BT.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BT.dir/depend


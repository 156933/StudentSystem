# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\github\StudentSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\github\StudentSystem\build

# Include any dependencies generated for this target.
include CMakeFiles/StudentSystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/StudentSystem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/StudentSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StudentSystem.dir/flags.make

CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj: CMakeFiles/StudentSystem.dir/flags.make
CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj: CMakeFiles/StudentSystem.dir/includes_C.rsp
CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj: E:/github/StudentSystem/src/StudentSystemManger.c
CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj: CMakeFiles/StudentSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\github\StudentSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj -MF CMakeFiles\StudentSystem.dir\src\StudentSystemManger.c.obj.d -o CMakeFiles\StudentSystem.dir\src\StudentSystemManger.c.obj -c E:\github\StudentSystem\src\StudentSystemManger.c

CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\github\StudentSystem\src\StudentSystemManger.c > CMakeFiles\StudentSystem.dir\src\StudentSystemManger.c.i

CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\github\StudentSystem\src\StudentSystemManger.c -o CMakeFiles\StudentSystem.dir\src\StudentSystemManger.c.s

# Object files for target StudentSystem
StudentSystem_OBJECTS = \
"CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj"

# External object files for target StudentSystem
StudentSystem_EXTERNAL_OBJECTS =

StudentSystem.exe: CMakeFiles/StudentSystem.dir/src/StudentSystemManger.c.obj
StudentSystem.exe: CMakeFiles/StudentSystem.dir/build.make
StudentSystem.exe: CMakeFiles/StudentSystem.dir/linkLibs.rsp
StudentSystem.exe: CMakeFiles/StudentSystem.dir/objects1.rsp
StudentSystem.exe: CMakeFiles/StudentSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\github\StudentSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable StudentSystem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StudentSystem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StudentSystem.dir/build: StudentSystem.exe
.PHONY : CMakeFiles/StudentSystem.dir/build

CMakeFiles/StudentSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StudentSystem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StudentSystem.dir/clean

CMakeFiles/StudentSystem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\github\StudentSystem E:\github\StudentSystem E:\github\StudentSystem\build E:\github\StudentSystem\build E:\github\StudentSystem\build\CMakeFiles\StudentSystem.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/StudentSystem.dir/depend


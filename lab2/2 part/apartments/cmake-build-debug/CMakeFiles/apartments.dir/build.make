# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\labs cLion\lab2\2 part\apartments"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\labs cLion\lab2\2 part\apartments\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/apartments.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/apartments.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/apartments.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/apartments.dir/flags.make

CMakeFiles/apartments.dir/library.cpp.obj: CMakeFiles/apartments.dir/flags.make
CMakeFiles/apartments.dir/library.cpp.obj: D:/labs\ cLion/lab2/2\ part/apartments/library.cpp
CMakeFiles/apartments.dir/library.cpp.obj: CMakeFiles/apartments.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\labs cLion\lab2\2 part\apartments\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/apartments.dir/library.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/apartments.dir/library.cpp.obj -MF CMakeFiles\apartments.dir\library.cpp.obj.d -o CMakeFiles\apartments.dir\library.cpp.obj -c "D:\labs cLion\lab2\2 part\apartments\library.cpp"

CMakeFiles/apartments.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/apartments.dir/library.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\labs cLion\lab2\2 part\apartments\library.cpp" > CMakeFiles\apartments.dir\library.cpp.i

CMakeFiles/apartments.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/apartments.dir/library.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\labs cLion\lab2\2 part\apartments\library.cpp" -o CMakeFiles\apartments.dir\library.cpp.s

# Object files for target apartments
apartments_OBJECTS = \
"CMakeFiles/apartments.dir/library.cpp.obj"

# External object files for target apartments
apartments_EXTERNAL_OBJECTS =

libapartments.a: CMakeFiles/apartments.dir/library.cpp.obj
libapartments.a: CMakeFiles/apartments.dir/build.make
libapartments.a: CMakeFiles/apartments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\labs cLion\lab2\2 part\apartments\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libapartments.a"
	$(CMAKE_COMMAND) -P CMakeFiles\apartments.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\apartments.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/apartments.dir/build: libapartments.a
.PHONY : CMakeFiles/apartments.dir/build

CMakeFiles/apartments.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\apartments.dir\cmake_clean.cmake
.PHONY : CMakeFiles/apartments.dir/clean

CMakeFiles/apartments.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\labs cLion\lab2\2 part\apartments" "D:\labs cLion\lab2\2 part\apartments" "D:\labs cLion\lab2\2 part\apartments\cmake-build-debug" "D:\labs cLion\lab2\2 part\apartments\cmake-build-debug" "D:\labs cLion\lab2\2 part\apartments\cmake-build-debug\CMakeFiles\apartments.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/apartments.dir/depend


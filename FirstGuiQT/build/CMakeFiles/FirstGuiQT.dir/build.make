# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Repository\C++\FirstGuiQT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Repository\C++\FirstGuiQT\build

# Include any dependencies generated for this target.
include CMakeFiles/FirstGuiQT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FirstGuiQT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FirstGuiQT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FirstGuiQT.dir/flags.make

CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj: CMakeFiles/FirstGuiQT.dir/flags.make
CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj: CMakeFiles/FirstGuiQT.dir/includes_CXX.rsp
CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj: FirstGuiQT_autogen/mocs_compilation.cpp
CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj: CMakeFiles/FirstGuiQT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Repository\C++\FirstGuiQT\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\FirstGuiQT.dir\FirstGuiQT_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\FirstGuiQT.dir\FirstGuiQT_autogen\mocs_compilation.cpp.obj -c C:\Repository\C++\FirstGuiQT\build\FirstGuiQT_autogen\mocs_compilation.cpp

CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Repository\C++\FirstGuiQT\build\FirstGuiQT_autogen\mocs_compilation.cpp > CMakeFiles\FirstGuiQT.dir\FirstGuiQT_autogen\mocs_compilation.cpp.i

CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Repository\C++\FirstGuiQT\build\FirstGuiQT_autogen\mocs_compilation.cpp -o CMakeFiles\FirstGuiQT.dir\FirstGuiQT_autogen\mocs_compilation.cpp.s

CMakeFiles/FirstGuiQT.dir/main.cpp.obj: CMakeFiles/FirstGuiQT.dir/flags.make
CMakeFiles/FirstGuiQT.dir/main.cpp.obj: CMakeFiles/FirstGuiQT.dir/includes_CXX.rsp
CMakeFiles/FirstGuiQT.dir/main.cpp.obj: ../main.cpp
CMakeFiles/FirstGuiQT.dir/main.cpp.obj: CMakeFiles/FirstGuiQT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Repository\C++\FirstGuiQT\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FirstGuiQT.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FirstGuiQT.dir/main.cpp.obj -MF CMakeFiles\FirstGuiQT.dir\main.cpp.obj.d -o CMakeFiles\FirstGuiQT.dir\main.cpp.obj -c C:\Repository\C++\FirstGuiQT\main.cpp

CMakeFiles/FirstGuiQT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstGuiQT.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Repository\C++\FirstGuiQT\main.cpp > CMakeFiles\FirstGuiQT.dir\main.cpp.i

CMakeFiles/FirstGuiQT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstGuiQT.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Repository\C++\FirstGuiQT\main.cpp -o CMakeFiles\FirstGuiQT.dir\main.cpp.s

CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj: CMakeFiles/FirstGuiQT.dir/flags.make
CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj: CMakeFiles/FirstGuiQT.dir/includes_CXX.rsp
CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj: ../mainwindow.cpp
CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj: CMakeFiles/FirstGuiQT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Repository\C++\FirstGuiQT\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj -MF CMakeFiles\FirstGuiQT.dir\mainwindow.cpp.obj.d -o CMakeFiles\FirstGuiQT.dir\mainwindow.cpp.obj -c C:\Repository\C++\FirstGuiQT\mainwindow.cpp

CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Repository\C++\FirstGuiQT\mainwindow.cpp > CMakeFiles\FirstGuiQT.dir\mainwindow.cpp.i

CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Repository\C++\FirstGuiQT\mainwindow.cpp -o CMakeFiles\FirstGuiQT.dir\mainwindow.cpp.s

# Object files for target FirstGuiQT
FirstGuiQT_OBJECTS = \
"CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/FirstGuiQT.dir/main.cpp.obj" \
"CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj"

# External object files for target FirstGuiQT
FirstGuiQT_EXTERNAL_OBJECTS =

FirstGuiQT.exe: CMakeFiles/FirstGuiQT.dir/FirstGuiQT_autogen/mocs_compilation.cpp.obj
FirstGuiQT.exe: CMakeFiles/FirstGuiQT.dir/main.cpp.obj
FirstGuiQT.exe: CMakeFiles/FirstGuiQT.dir/mainwindow.cpp.obj
FirstGuiQT.exe: CMakeFiles/FirstGuiQT.dir/build.make
FirstGuiQT.exe: C:/msys64/mingw64/lib/libQt5Widgets.dll.a
FirstGuiQT.exe: C:/msys64/mingw64/lib/libQt5Gui.dll.a
FirstGuiQT.exe: C:/msys64/mingw64/lib/libQt5Core.dll.a
FirstGuiQT.exe: CMakeFiles/FirstGuiQT.dir/linklibs.rsp
FirstGuiQT.exe: CMakeFiles/FirstGuiQT.dir/objects1.rsp
FirstGuiQT.exe: CMakeFiles/FirstGuiQT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Repository\C++\FirstGuiQT\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable FirstGuiQT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FirstGuiQT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FirstGuiQT.dir/build: FirstGuiQT.exe
.PHONY : CMakeFiles/FirstGuiQT.dir/build

CMakeFiles/FirstGuiQT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FirstGuiQT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FirstGuiQT.dir/clean

CMakeFiles/FirstGuiQT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Repository\C++\FirstGuiQT C:\Repository\C++\FirstGuiQT C:\Repository\C++\FirstGuiQT\build C:\Repository\C++\FirstGuiQT\build C:\Repository\C++\FirstGuiQT\build\CMakeFiles\FirstGuiQT.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FirstGuiQT.dir/depend


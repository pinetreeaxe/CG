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
CMAKE_SOURCE_DIR = /home/gustavo/Documents/CG/CG/Fase1/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gustavo/Documents/CG/CG/Fase1/src/NewBuild

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/engine.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine.cpp.o: ../engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/engine.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/engine.cpp

CMakeFiles/engine.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/engine.cpp > CMakeFiles/engine.dir/engine.cpp.i

CMakeFiles/engine.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/engine.cpp -o CMakeFiles/engine.dir/engine.cpp.s

CMakeFiles/engine.dir/engine.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/engine.cpp.o.requires

CMakeFiles/engine.dir/engine.cpp.o.provides: CMakeFiles/engine.dir/engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/engine.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/engine.cpp.o.provides

CMakeFiles/engine.dir/engine.cpp.o.provides.build: CMakeFiles/engine.dir/engine.cpp.o


CMakeFiles/engine.dir/point.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/point.cpp.o: ../point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/point.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/point.cpp

CMakeFiles/engine.dir/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/point.cpp > CMakeFiles/engine.dir/point.cpp.i

CMakeFiles/engine.dir/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/point.cpp -o CMakeFiles/engine.dir/point.cpp.s

CMakeFiles/engine.dir/point.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/point.cpp.o.requires

CMakeFiles/engine.dir/point.cpp.o.provides: CMakeFiles/engine.dir/point.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/point.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/point.cpp.o.provides

CMakeFiles/engine.dir/point.cpp.o.provides.build: CMakeFiles/engine.dir/point.cpp.o


CMakeFiles/engine.dir/vector.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/vector.cpp.o: ../vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/vector.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/vector.cpp

CMakeFiles/engine.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/vector.cpp > CMakeFiles/engine.dir/vector.cpp.i

CMakeFiles/engine.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/vector.cpp -o CMakeFiles/engine.dir/vector.cpp.s

CMakeFiles/engine.dir/vector.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/vector.cpp.o.requires

CMakeFiles/engine.dir/vector.cpp.o.provides: CMakeFiles/engine.dir/vector.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/vector.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/vector.cpp.o.provides

CMakeFiles/engine.dir/vector.cpp.o.provides.build: CMakeFiles/engine.dir/vector.cpp.o


CMakeFiles/engine.dir/tinyxml2.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/tinyxml2.cpp.o: ../tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/tinyxml2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/tinyxml2.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/tinyxml2.cpp

CMakeFiles/engine.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/tinyxml2.cpp > CMakeFiles/engine.dir/tinyxml2.cpp.i

CMakeFiles/engine.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/tinyxml2.cpp -o CMakeFiles/engine.dir/tinyxml2.cpp.s

CMakeFiles/engine.dir/tinyxml2.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/tinyxml2.cpp.o.requires

CMakeFiles/engine.dir/tinyxml2.cpp.o.provides: CMakeFiles/engine.dir/tinyxml2.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/tinyxml2.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/tinyxml2.cpp.o.provides

CMakeFiles/engine.dir/tinyxml2.cpp.o.provides.build: CMakeFiles/engine.dir/tinyxml2.cpp.o


CMakeFiles/engine.dir/models.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/models.cpp.o: ../models.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/models.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/models.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/models.cpp

CMakeFiles/engine.dir/models.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/models.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/models.cpp > CMakeFiles/engine.dir/models.cpp.i

CMakeFiles/engine.dir/models.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/models.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/models.cpp -o CMakeFiles/engine.dir/models.cpp.s

CMakeFiles/engine.dir/models.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/models.cpp.o.requires

CMakeFiles/engine.dir/models.cpp.o.provides: CMakeFiles/engine.dir/models.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/models.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/models.cpp.o.provides

CMakeFiles/engine.dir/models.cpp.o.provides.build: CMakeFiles/engine.dir/models.cpp.o


CMakeFiles/engine.dir/sphericalpoint.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/sphericalpoint.cpp.o: ../sphericalpoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine.dir/sphericalpoint.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/sphericalpoint.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/sphericalpoint.cpp

CMakeFiles/engine.dir/sphericalpoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/sphericalpoint.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/sphericalpoint.cpp > CMakeFiles/engine.dir/sphericalpoint.cpp.i

CMakeFiles/engine.dir/sphericalpoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/sphericalpoint.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/sphericalpoint.cpp -o CMakeFiles/engine.dir/sphericalpoint.cpp.s

CMakeFiles/engine.dir/sphericalpoint.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/sphericalpoint.cpp.o.requires

CMakeFiles/engine.dir/sphericalpoint.cpp.o.provides: CMakeFiles/engine.dir/sphericalpoint.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/sphericalpoint.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/sphericalpoint.cpp.o.provides

CMakeFiles/engine.dir/sphericalpoint.cpp.o.provides.build: CMakeFiles/engine.dir/sphericalpoint.cpp.o


CMakeFiles/engine.dir/transformation.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/transformation.cpp.o: ../transformation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/engine.dir/transformation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/transformation.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/transformation.cpp

CMakeFiles/engine.dir/transformation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/transformation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/transformation.cpp > CMakeFiles/engine.dir/transformation.cpp.i

CMakeFiles/engine.dir/transformation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/transformation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/transformation.cpp -o CMakeFiles/engine.dir/transformation.cpp.s

CMakeFiles/engine.dir/transformation.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/transformation.cpp.o.requires

CMakeFiles/engine.dir/transformation.cpp.o.provides: CMakeFiles/engine.dir/transformation.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/transformation.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/transformation.cpp.o.provides

CMakeFiles/engine.dir/transformation.cpp.o.provides.build: CMakeFiles/engine.dir/transformation.cpp.o


CMakeFiles/engine.dir/lights.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/lights.cpp.o: ../lights.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/engine.dir/lights.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/lights.cpp.o -c /home/gustavo/Documents/CG/CG/Fase1/src/lights.cpp

CMakeFiles/engine.dir/lights.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/lights.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documents/CG/CG/Fase1/src/lights.cpp > CMakeFiles/engine.dir/lights.cpp.i

CMakeFiles/engine.dir/lights.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/lights.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documents/CG/CG/Fase1/src/lights.cpp -o CMakeFiles/engine.dir/lights.cpp.s

CMakeFiles/engine.dir/lights.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/lights.cpp.o.requires

CMakeFiles/engine.dir/lights.cpp.o.provides: CMakeFiles/engine.dir/lights.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/lights.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/lights.cpp.o.provides

CMakeFiles/engine.dir/lights.cpp.o.provides.build: CMakeFiles/engine.dir/lights.cpp.o


# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/engine.cpp.o" \
"CMakeFiles/engine.dir/point.cpp.o" \
"CMakeFiles/engine.dir/vector.cpp.o" \
"CMakeFiles/engine.dir/tinyxml2.cpp.o" \
"CMakeFiles/engine.dir/models.cpp.o" \
"CMakeFiles/engine.dir/sphericalpoint.cpp.o" \
"CMakeFiles/engine.dir/transformation.cpp.o" \
"CMakeFiles/engine.dir/lights.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine: CMakeFiles/engine.dir/engine.cpp.o
engine: CMakeFiles/engine.dir/point.cpp.o
engine: CMakeFiles/engine.dir/vector.cpp.o
engine: CMakeFiles/engine.dir/tinyxml2.cpp.o
engine: CMakeFiles/engine.dir/models.cpp.o
engine: CMakeFiles/engine.dir/sphericalpoint.cpp.o
engine: CMakeFiles/engine.dir/transformation.cpp.o
engine: CMakeFiles/engine.dir/lights.cpp.o
engine: CMakeFiles/engine.dir/build.make
engine: /usr/lib/x86_64-linux-gnu/libGL.so
engine: /usr/lib/x86_64-linux-gnu/libGLU.so
engine: /usr/lib/x86_64-linux-gnu/libglut.so
engine: /usr/lib/x86_64-linux-gnu/libXmu.so
engine: /usr/lib/x86_64-linux-gnu/libXi.so
engine: /usr/lib/x86_64-linux-gnu/libGLEW.so
engine: /usr/lib/x86_64-linux-gnu/libIL.so
engine: CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: engine

.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/engine.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/point.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/vector.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/tinyxml2.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/models.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/sphericalpoint.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/transformation.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/lights.cpp.o.requires

.PHONY : CMakeFiles/engine.dir/requires

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/gustavo/Documents/CG/CG/Fase1/src/NewBuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gustavo/Documents/CG/CG/Fase1/src /home/gustavo/Documents/CG/CG/Fase1/src /home/gustavo/Documents/CG/CG/Fase1/src/NewBuild /home/gustavo/Documents/CG/CG/Fase1/src/NewBuild /home/gustavo/Documents/CG/CG/Fase1/src/NewBuild/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/malcolm/plexydesk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malcolm/plexydesk

# Include any dependencies generated for this target.
include 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/depend.make

# Include the progress variables for this target.
include 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/progress.make

# Include the compile flags for this target's objects.
include 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/flags.make

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o: 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/flags.make
3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o: 3rdparty/qplexyiconprovider/tests/test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/malcolm/plexydesk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o"
	cd /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/plexyiconprovidertest.dir/test.o -c /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests/test.cpp

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plexyiconprovidertest.dir/test.i"
	cd /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests/test.cpp > CMakeFiles/plexyiconprovidertest.dir/test.i

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plexyiconprovidertest.dir/test.s"
	cd /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests/test.cpp -o CMakeFiles/plexyiconprovidertest.dir/test.s

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.requires:
.PHONY : 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.requires

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.provides: 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.requires
	$(MAKE) -f 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/build.make 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.provides.build
.PHONY : 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.provides

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.provides.build: 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o
.PHONY : 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.provides.build

# Object files for target plexyiconprovidertest
plexyiconprovidertest_OBJECTS = \
"CMakeFiles/plexyiconprovidertest.dir/test.o"

# External object files for target plexyiconprovidertest
plexyiconprovidertest_EXTERNAL_OBJECTS =

3rdparty/qplexyiconprovider/tests/plexyiconprovidertest: 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o
3rdparty/qplexyiconprovider/tests/plexyiconprovidertest: 3rdparty/qplexyiconprovider/libplexyiconprovider.so
3rdparty/qplexyiconprovider/tests/plexyiconprovidertest: /usr/local/Trolltech/Qt-4.5.1/lib/libQtCore.so
3rdparty/qplexyiconprovider/tests/plexyiconprovidertest: /usr/local/Trolltech/Qt-4.5.1/lib/libQtGui.so
3rdparty/qplexyiconprovider/tests/plexyiconprovidertest: 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/build.make
3rdparty/qplexyiconprovider/tests/plexyiconprovidertest: 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable plexyiconprovidertest"
	cd /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plexyiconprovidertest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/build: 3rdparty/qplexyiconprovider/tests/plexyiconprovidertest
.PHONY : 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/build

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/requires: 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/test.o.requires
.PHONY : 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/requires

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/clean:
	cd /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests && $(CMAKE_COMMAND) -P CMakeFiles/plexyiconprovidertest.dir/cmake_clean.cmake
.PHONY : 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/clean

3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/depend:
	cd /home/malcolm/plexydesk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malcolm/plexydesk /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests /home/malcolm/plexydesk /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests /home/malcolm/plexydesk/3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3rdparty/qplexyiconprovider/tests/CMakeFiles/plexyiconprovidertest.dir/depend


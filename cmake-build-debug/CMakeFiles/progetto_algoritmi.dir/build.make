# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/34/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/34/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = $HOME/Scrivania/progetto_algoritmi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = $HOME/Scrivania/progetto_algoritmi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/progetto_algoritmi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/progetto_algoritmi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progetto_algoritmi.dir/flags.make

CMakeFiles/progetto_algoritmi.dir/main.cpp.o: CMakeFiles/progetto_algoritmi.dir/flags.make
CMakeFiles/progetto_algoritmi.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=$HOME/Scrivania/progetto_algoritmi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/progetto_algoritmi.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progetto_algoritmi.dir/main.cpp.o -c $HOME/Scrivania/progetto_algoritmi/main.cpp

CMakeFiles/progetto_algoritmi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progetto_algoritmi.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E $HOME/Scrivania/progetto_algoritmi/main.cpp > CMakeFiles/progetto_algoritmi.dir/main.cpp.i

CMakeFiles/progetto_algoritmi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progetto_algoritmi.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S $HOME/Scrivania/progetto_algoritmi/main.cpp -o CMakeFiles/progetto_algoritmi.dir/main.cpp.s

CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.o: CMakeFiles/progetto_algoritmi.dir/flags.make
CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.o: ../FileHandlingClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=$HOME/Scrivania/progetto_algoritmi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.o -c $HOME/Scrivania/progetto_algoritmi/FileHandlingClass.cpp

CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E $HOME/Scrivania/progetto_algoritmi/FileHandlingClass.cpp > CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.i

CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S $HOME/Scrivania/progetto_algoritmi/FileHandlingClass.cpp -o CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.s

CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.o: CMakeFiles/progetto_algoritmi.dir/flags.make
CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.o: ../UtenteGenerico.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=$HOME/Scrivania/progetto_algoritmi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.o -c $HOME/Scrivania/progetto_algoritmi/UtenteGenerico.cpp

CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E $HOME/Scrivania/progetto_algoritmi/UtenteGenerico.cpp > CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.i

CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S $HOME/Scrivania/progetto_algoritmi/UtenteGenerico.cpp -o CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.s

# Object files for target progetto_algoritmi
progetto_algoritmi_OBJECTS = \
"CMakeFiles/progetto_algoritmi.dir/main.cpp.o" \
"CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.o" \
"CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.o"

# External object files for target progetto_algoritmi
progetto_algoritmi_EXTERNAL_OBJECTS =

progetto_algoritmi: CMakeFiles/progetto_algoritmi.dir/main.cpp.o
progetto_algoritmi: CMakeFiles/progetto_algoritmi.dir/FileHandlingClass.cpp.o
progetto_algoritmi: CMakeFiles/progetto_algoritmi.dir/UtenteGenerico.cpp.o
progetto_algoritmi: CMakeFiles/progetto_algoritmi.dir/build.make
progetto_algoritmi: CMakeFiles/progetto_algoritmi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=$HOME/Scrivania/progetto_algoritmi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable progetto_algoritmi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progetto_algoritmi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progetto_algoritmi.dir/build: progetto_algoritmi

.PHONY : CMakeFiles/progetto_algoritmi.dir/build

CMakeFiles/progetto_algoritmi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/progetto_algoritmi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/progetto_algoritmi.dir/clean

CMakeFiles/progetto_algoritmi.dir/depend:
	cd $HOME/Scrivania/progetto_algoritmi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" $HOME/Scrivania/progetto_algoritmi $HOME/Scrivania/progetto_algoritmi $HOME/Scrivania/progetto_algoritmi/cmake-build-debug $HOME/Scrivania/progetto_algoritmi/cmake-build-debug $HOME/Scrivania/progetto_algoritmi/cmake-build-debug/CMakeFiles/progetto_algoritmi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/progetto_algoritmi.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mac/projects/pico/pico-sdk/tools/pioasm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mac/projects/pico/dma_uart/build/pioasm

# Include any dependencies generated for this target.
include CMakeFiles/pioasm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pioasm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pioasm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pioasm.dir/flags.make

CMakeFiles/pioasm.dir/main.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/main.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/main.cpp
CMakeFiles/pioasm.dir/main.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pioasm.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/main.cpp.o -MF CMakeFiles/pioasm.dir/main.cpp.o.d -o CMakeFiles/pioasm.dir/main.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/main.cpp

CMakeFiles/pioasm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/main.cpp > CMakeFiles/pioasm.dir/main.cpp.i

CMakeFiles/pioasm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/main.cpp -o CMakeFiles/pioasm.dir/main.cpp.s

CMakeFiles/pioasm.dir/pio_assembler.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/pio_assembler.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_assembler.cpp
CMakeFiles/pioasm.dir/pio_assembler.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pioasm.dir/pio_assembler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/pio_assembler.cpp.o -MF CMakeFiles/pioasm.dir/pio_assembler.cpp.o.d -o CMakeFiles/pioasm.dir/pio_assembler.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_assembler.cpp

CMakeFiles/pioasm.dir/pio_assembler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/pio_assembler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_assembler.cpp > CMakeFiles/pioasm.dir/pio_assembler.cpp.i

CMakeFiles/pioasm.dir/pio_assembler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/pio_assembler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_assembler.cpp -o CMakeFiles/pioasm.dir/pio_assembler.cpp.s

CMakeFiles/pioasm.dir/pio_disassembler.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/pio_disassembler.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_disassembler.cpp
CMakeFiles/pioasm.dir/pio_disassembler.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pioasm.dir/pio_disassembler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/pio_disassembler.cpp.o -MF CMakeFiles/pioasm.dir/pio_disassembler.cpp.o.d -o CMakeFiles/pioasm.dir/pio_disassembler.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_disassembler.cpp

CMakeFiles/pioasm.dir/pio_disassembler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/pio_disassembler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_disassembler.cpp > CMakeFiles/pioasm.dir/pio_disassembler.cpp.i

CMakeFiles/pioasm.dir/pio_disassembler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/pio_disassembler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/pio_disassembler.cpp -o CMakeFiles/pioasm.dir/pio_disassembler.cpp.s

CMakeFiles/pioasm.dir/gen/lexer.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/gen/lexer.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/lexer.cpp
CMakeFiles/pioasm.dir/gen/lexer.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pioasm.dir/gen/lexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/gen/lexer.cpp.o -MF CMakeFiles/pioasm.dir/gen/lexer.cpp.o.d -o CMakeFiles/pioasm.dir/gen/lexer.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/lexer.cpp

CMakeFiles/pioasm.dir/gen/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/gen/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/lexer.cpp > CMakeFiles/pioasm.dir/gen/lexer.cpp.i

CMakeFiles/pioasm.dir/gen/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/gen/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/lexer.cpp -o CMakeFiles/pioasm.dir/gen/lexer.cpp.s

CMakeFiles/pioasm.dir/gen/parser.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/gen/parser.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/parser.cpp
CMakeFiles/pioasm.dir/gen/parser.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pioasm.dir/gen/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/gen/parser.cpp.o -MF CMakeFiles/pioasm.dir/gen/parser.cpp.o.d -o CMakeFiles/pioasm.dir/gen/parser.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/parser.cpp

CMakeFiles/pioasm.dir/gen/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/gen/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/parser.cpp > CMakeFiles/pioasm.dir/gen/parser.cpp.i

CMakeFiles/pioasm.dir/gen/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/gen/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/gen/parser.cpp -o CMakeFiles/pioasm.dir/gen/parser.cpp.s

CMakeFiles/pioasm.dir/c_sdk_output.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/c_sdk_output.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/c_sdk_output.cpp
CMakeFiles/pioasm.dir/c_sdk_output.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pioasm.dir/c_sdk_output.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/c_sdk_output.cpp.o -MF CMakeFiles/pioasm.dir/c_sdk_output.cpp.o.d -o CMakeFiles/pioasm.dir/c_sdk_output.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/c_sdk_output.cpp

CMakeFiles/pioasm.dir/c_sdk_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/c_sdk_output.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/c_sdk_output.cpp > CMakeFiles/pioasm.dir/c_sdk_output.cpp.i

CMakeFiles/pioasm.dir/c_sdk_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/c_sdk_output.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/c_sdk_output.cpp -o CMakeFiles/pioasm.dir/c_sdk_output.cpp.s

CMakeFiles/pioasm.dir/python_output.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/python_output.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/python_output.cpp
CMakeFiles/pioasm.dir/python_output.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pioasm.dir/python_output.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/python_output.cpp.o -MF CMakeFiles/pioasm.dir/python_output.cpp.o.d -o CMakeFiles/pioasm.dir/python_output.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/python_output.cpp

CMakeFiles/pioasm.dir/python_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/python_output.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/python_output.cpp > CMakeFiles/pioasm.dir/python_output.cpp.i

CMakeFiles/pioasm.dir/python_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/python_output.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/python_output.cpp -o CMakeFiles/pioasm.dir/python_output.cpp.s

CMakeFiles/pioasm.dir/hex_output.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/hex_output.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/hex_output.cpp
CMakeFiles/pioasm.dir/hex_output.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pioasm.dir/hex_output.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/hex_output.cpp.o -MF CMakeFiles/pioasm.dir/hex_output.cpp.o.d -o CMakeFiles/pioasm.dir/hex_output.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/hex_output.cpp

CMakeFiles/pioasm.dir/hex_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/hex_output.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/hex_output.cpp > CMakeFiles/pioasm.dir/hex_output.cpp.i

CMakeFiles/pioasm.dir/hex_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/hex_output.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/hex_output.cpp -o CMakeFiles/pioasm.dir/hex_output.cpp.s

CMakeFiles/pioasm.dir/ada_output.cpp.o: CMakeFiles/pioasm.dir/flags.make
CMakeFiles/pioasm.dir/ada_output.cpp.o: /home/mac/projects/pico/pico-sdk/tools/pioasm/ada_output.cpp
CMakeFiles/pioasm.dir/ada_output.cpp.o: CMakeFiles/pioasm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pioasm.dir/ada_output.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pioasm.dir/ada_output.cpp.o -MF CMakeFiles/pioasm.dir/ada_output.cpp.o.d -o CMakeFiles/pioasm.dir/ada_output.cpp.o -c /home/mac/projects/pico/pico-sdk/tools/pioasm/ada_output.cpp

CMakeFiles/pioasm.dir/ada_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/ada_output.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/projects/pico/pico-sdk/tools/pioasm/ada_output.cpp > CMakeFiles/pioasm.dir/ada_output.cpp.i

CMakeFiles/pioasm.dir/ada_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/ada_output.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/projects/pico/pico-sdk/tools/pioasm/ada_output.cpp -o CMakeFiles/pioasm.dir/ada_output.cpp.s

# Object files for target pioasm
pioasm_OBJECTS = \
"CMakeFiles/pioasm.dir/main.cpp.o" \
"CMakeFiles/pioasm.dir/pio_assembler.cpp.o" \
"CMakeFiles/pioasm.dir/pio_disassembler.cpp.o" \
"CMakeFiles/pioasm.dir/gen/lexer.cpp.o" \
"CMakeFiles/pioasm.dir/gen/parser.cpp.o" \
"CMakeFiles/pioasm.dir/c_sdk_output.cpp.o" \
"CMakeFiles/pioasm.dir/python_output.cpp.o" \
"CMakeFiles/pioasm.dir/hex_output.cpp.o" \
"CMakeFiles/pioasm.dir/ada_output.cpp.o"

# External object files for target pioasm
pioasm_EXTERNAL_OBJECTS =

pioasm: CMakeFiles/pioasm.dir/main.cpp.o
pioasm: CMakeFiles/pioasm.dir/pio_assembler.cpp.o
pioasm: CMakeFiles/pioasm.dir/pio_disassembler.cpp.o
pioasm: CMakeFiles/pioasm.dir/gen/lexer.cpp.o
pioasm: CMakeFiles/pioasm.dir/gen/parser.cpp.o
pioasm: CMakeFiles/pioasm.dir/c_sdk_output.cpp.o
pioasm: CMakeFiles/pioasm.dir/python_output.cpp.o
pioasm: CMakeFiles/pioasm.dir/hex_output.cpp.o
pioasm: CMakeFiles/pioasm.dir/ada_output.cpp.o
pioasm: CMakeFiles/pioasm.dir/build.make
pioasm: CMakeFiles/pioasm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable pioasm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pioasm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pioasm.dir/build: pioasm
.PHONY : CMakeFiles/pioasm.dir/build

CMakeFiles/pioasm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pioasm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pioasm.dir/clean

CMakeFiles/pioasm.dir/depend:
	cd /home/mac/projects/pico/dma_uart/build/pioasm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mac/projects/pico/pico-sdk/tools/pioasm /home/mac/projects/pico/pico-sdk/tools/pioasm /home/mac/projects/pico/dma_uart/build/pioasm /home/mac/projects/pico/dma_uart/build/pioasm /home/mac/projects/pico/dma_uart/build/pioasm/CMakeFiles/pioasm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pioasm.dir/depend


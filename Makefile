# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Programok\cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Programok\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Alonso\Documents\Visual Studio Code\Ballbreaker3D2016"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Alonso\Documents\Visual Studio Code\Ballbreaker3D2016"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	D:\Programok\cmake\bin\cmake-gui.exe -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	D:\Programok\cmake\bin\cmake.exe -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "D:\Alonso\Documents\Visual Studio Code\Ballbreaker3D2016\CMakeFiles" "D:\Alonso\Documents\Visual Studio Code\Ballbreaker3D2016\CMakeFiles\progress.marks"
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "D:\Alonso\Documents\Visual Studio Code\Ballbreaker3D2016\CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named BallBreaker3D

# Build rule for target.
BallBreaker3D: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 BallBreaker3D
.PHONY : BallBreaker3D

# fast build rule for target.
BallBreaker3D/fast:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/build
.PHONY : BallBreaker3D/fast

Application.obj: Application.cpp.obj

.PHONY : Application.obj

# target to build an object file
Application.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Application.cpp.obj
.PHONY : Application.cpp.obj

Application.i: Application.cpp.i

.PHONY : Application.i

# target to preprocess a source file
Application.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Application.cpp.i
.PHONY : Application.cpp.i

Application.s: Application.cpp.s

.PHONY : Application.s

# target to generate assembly for a file
Application.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Application.cpp.s
.PHONY : Application.cpp.s

Ball.obj: Ball.cpp.obj

.PHONY : Ball.obj

# target to build an object file
Ball.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Ball.cpp.obj
.PHONY : Ball.cpp.obj

Ball.i: Ball.cpp.i

.PHONY : Ball.i

# target to preprocess a source file
Ball.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Ball.cpp.i
.PHONY : Ball.cpp.i

Ball.s: Ball.cpp.s

.PHONY : Ball.s

# target to generate assembly for a file
Ball.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Ball.cpp.s
.PHONY : Ball.cpp.s

Block.obj: Block.cpp.obj

.PHONY : Block.obj

# target to build an object file
Block.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Block.cpp.obj
.PHONY : Block.cpp.obj

Block.i: Block.cpp.i

.PHONY : Block.i

# target to preprocess a source file
Block.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Block.cpp.i
.PHONY : Block.cpp.i

Block.s: Block.cpp.s

.PHONY : Block.s

# target to generate assembly for a file
Block.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Block.cpp.s
.PHONY : Block.cpp.s

FileManager.obj: FileManager.cpp.obj

.PHONY : FileManager.obj

# target to build an object file
FileManager.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/FileManager.cpp.obj
.PHONY : FileManager.cpp.obj

FileManager.i: FileManager.cpp.i

.PHONY : FileManager.i

# target to preprocess a source file
FileManager.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/FileManager.cpp.i
.PHONY : FileManager.cpp.i

FileManager.s: FileManager.cpp.s

.PHONY : FileManager.s

# target to generate assembly for a file
FileManager.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/FileManager.cpp.s
.PHONY : FileManager.cpp.s

Game.obj: Game.cpp.obj

.PHONY : Game.obj

# target to build an object file
Game.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Game.cpp.obj
.PHONY : Game.cpp.obj

Game.i: Game.cpp.i

.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s

.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Game.cpp.s
.PHONY : Game.cpp.s

Level.obj: Level.cpp.obj

.PHONY : Level.obj

# target to build an object file
Level.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Level.cpp.obj
.PHONY : Level.cpp.obj

Level.i: Level.cpp.i

.PHONY : Level.i

# target to preprocess a source file
Level.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Level.cpp.i
.PHONY : Level.cpp.i

Level.s: Level.cpp.s

.PHONY : Level.s

# target to generate assembly for a file
Level.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Level.cpp.s
.PHONY : Level.cpp.s

Menu.obj: Menu.cpp.obj

.PHONY : Menu.obj

# target to build an object file
Menu.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Menu.cpp.obj
.PHONY : Menu.cpp.obj

Menu.i: Menu.cpp.i

.PHONY : Menu.i

# target to preprocess a source file
Menu.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Menu.cpp.i
.PHONY : Menu.cpp.i

Menu.s: Menu.cpp.s

.PHONY : Menu.s

# target to generate assembly for a file
Menu.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Menu.cpp.s
.PHONY : Menu.cpp.s

Model.obj: Model.cpp.obj

.PHONY : Model.obj

# target to build an object file
Model.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Model.cpp.obj
.PHONY : Model.cpp.obj

Model.i: Model.cpp.i

.PHONY : Model.i

# target to preprocess a source file
Model.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Model.cpp.i
.PHONY : Model.cpp.i

Model.s: Model.cpp.s

.PHONY : Model.s

# target to generate assembly for a file
Model.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Model.cpp.s
.PHONY : Model.cpp.s

Object.obj: Object.cpp.obj

.PHONY : Object.obj

# target to build an object file
Object.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Object.cpp.obj
.PHONY : Object.cpp.obj

Object.i: Object.cpp.i

.PHONY : Object.i

# target to preprocess a source file
Object.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Object.cpp.i
.PHONY : Object.cpp.i

Object.s: Object.cpp.s

.PHONY : Object.s

# target to generate assembly for a file
Object.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Object.cpp.s
.PHONY : Object.cpp.s

Player.obj: Player.cpp.obj

.PHONY : Player.obj

# target to build an object file
Player.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Player.cpp.obj
.PHONY : Player.cpp.obj

Player.i: Player.cpp.i

.PHONY : Player.i

# target to preprocess a source file
Player.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Player.cpp.i
.PHONY : Player.cpp.i

Player.s: Player.cpp.s

.PHONY : Player.s

# target to generate assembly for a file
Player.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Player.cpp.s
.PHONY : Player.cpp.s

Sound.obj: Sound.cpp.obj

.PHONY : Sound.obj

# target to build an object file
Sound.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Sound.cpp.obj
.PHONY : Sound.cpp.obj

Sound.i: Sound.cpp.i

.PHONY : Sound.i

# target to preprocess a source file
Sound.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Sound.cpp.i
.PHONY : Sound.cpp.i

Sound.s: Sound.cpp.s

.PHONY : Sound.s

# target to generate assembly for a file
Sound.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Sound.cpp.s
.PHONY : Sound.cpp.s

Texture.obj: Texture.cpp.obj

.PHONY : Texture.obj

# target to build an object file
Texture.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Texture.cpp.obj
.PHONY : Texture.cpp.obj

Texture.i: Texture.cpp.i

.PHONY : Texture.i

# target to preprocess a source file
Texture.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Texture.cpp.i
.PHONY : Texture.cpp.i

Texture.s: Texture.cpp.s

.PHONY : Texture.s

# target to generate assembly for a file
Texture.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/Texture.cpp.s
.PHONY : Texture.cpp.s

main.obj: main.cpp.obj

.PHONY : main.obj

# target to build an object file
main.cpp.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/main.cpp.obj
.PHONY : main.cpp.obj

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/main.cpp.s
.PHONY : main.cpp.s

resource.obj: resource.rc.obj

.PHONY : resource.obj

# target to build an object file
resource.rc.obj:
	$(MAKE) -f CMakeFiles\BallBreaker3D.dir\build.make CMakeFiles/BallBreaker3D.dir/resource.rc.obj
.PHONY : resource.rc.obj

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... BallBreaker3D
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... Application.obj
	@echo ... Application.i
	@echo ... Application.s
	@echo ... Ball.obj
	@echo ... Ball.i
	@echo ... Ball.s
	@echo ... Block.obj
	@echo ... Block.i
	@echo ... Block.s
	@echo ... FileManager.obj
	@echo ... FileManager.i
	@echo ... FileManager.s
	@echo ... Game.obj
	@echo ... Game.i
	@echo ... Game.s
	@echo ... Level.obj
	@echo ... Level.i
	@echo ... Level.s
	@echo ... Menu.obj
	@echo ... Menu.i
	@echo ... Menu.s
	@echo ... Model.obj
	@echo ... Model.i
	@echo ... Model.s
	@echo ... Object.obj
	@echo ... Object.i
	@echo ... Object.s
	@echo ... Player.obj
	@echo ... Player.i
	@echo ... Player.s
	@echo ... Sound.obj
	@echo ... Sound.i
	@echo ... Sound.s
	@echo ... Texture.obj
	@echo ... Texture.i
	@echo ... Texture.s
	@echo ... main.obj
	@echo ... main.i
	@echo ... main.s
	@echo ... resource.obj
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system


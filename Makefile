# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_SOURCE_DIR = /home/itzik/Desktop/zaf1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/itzik/Desktop/zaf1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/itzik/Desktop/zaf1/CMakeFiles /home/itzik/Desktop/zaf1/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/itzik/Desktop/zaf1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

Actors.o: Actors.cpp.o
.PHONY : Actors.o

# target to build an object file
Actors.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Actors.cpp.o
.PHONY : Actors.cpp.o

Actors.i: Actors.cpp.i
.PHONY : Actors.i

# target to preprocess a source file
Actors.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Actors.cpp.i
.PHONY : Actors.cpp.i

Actors.s: Actors.cpp.s
.PHONY : Actors.s

# target to generate assembly for a file
Actors.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Actors.cpp.s
.PHONY : Actors.cpp.s

Armor.o: Armor.cpp.o
.PHONY : Armor.o

# target to build an object file
Armor.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Armor.cpp.o
.PHONY : Armor.cpp.o

Armor.i: Armor.cpp.i
.PHONY : Armor.i

# target to preprocess a source file
Armor.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Armor.cpp.i
.PHONY : Armor.cpp.i

Armor.s: Armor.cpp.s
.PHONY : Armor.s

# target to generate assembly for a file
Armor.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Armor.cpp.s
.PHONY : Armor.cpp.s

Console.o: Console.cpp.o
.PHONY : Console.o

# target to build an object file
Console.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Console.cpp.o
.PHONY : Console.cpp.o

Console.i: Console.cpp.i
.PHONY : Console.i

# target to preprocess a source file
Console.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Console.cpp.i
.PHONY : Console.cpp.i

Console.s: Console.cpp.s
.PHONY : Console.s

# target to generate assembly for a file
Console.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Console.cpp.s
.PHONY : Console.cpp.s

Enemy.o: Enemy.cpp.o
.PHONY : Enemy.o

# target to build an object file
Enemy.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.o
.PHONY : Enemy.cpp.o

Enemy.i: Enemy.cpp.i
.PHONY : Enemy.i

# target to preprocess a source file
Enemy.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.i
.PHONY : Enemy.cpp.i

Enemy.s: Enemy.cpp.s
.PHONY : Enemy.s

# target to generate assembly for a file
Enemy.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.s
.PHONY : Enemy.cpp.s

Game.o: Game.cpp.o
.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i
.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s
.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Game.cpp.s
.PHONY : Game.cpp.s

Hero.o: Hero.cpp.o
.PHONY : Hero.o

# target to build an object file
Hero.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Hero.cpp.o
.PHONY : Hero.cpp.o

Hero.i: Hero.cpp.i
.PHONY : Hero.i

# target to preprocess a source file
Hero.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Hero.cpp.i
.PHONY : Hero.cpp.i

Hero.s: Hero.cpp.s
.PHONY : Hero.s

# target to generate assembly for a file
Hero.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Hero.cpp.s
.PHONY : Hero.cpp.s

Item.o: Item.cpp.o
.PHONY : Item.o

# target to build an object file
Item.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Item.cpp.o
.PHONY : Item.cpp.o

Item.i: Item.cpp.i
.PHONY : Item.i

# target to preprocess a source file
Item.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Item.cpp.i
.PHONY : Item.cpp.i

Item.s: Item.cpp.s
.PHONY : Item.s

# target to generate assembly for a file
Item.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Item.cpp.s
.PHONY : Item.cpp.s

Point2d.o: Point2d.cpp.o
.PHONY : Point2d.o

# target to build an object file
Point2d.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Point2d.cpp.o
.PHONY : Point2d.cpp.o

Point2d.i: Point2d.cpp.i
.PHONY : Point2d.i

# target to preprocess a source file
Point2d.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Point2d.cpp.i
.PHONY : Point2d.cpp.i

Point2d.s: Point2d.cpp.s
.PHONY : Point2d.s

# target to generate assembly for a file
Point2d.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Point2d.cpp.s
.PHONY : Point2d.cpp.s

Potion.o: Potion.cpp.o
.PHONY : Potion.o

# target to build an object file
Potion.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Potion.cpp.o
.PHONY : Potion.cpp.o

Potion.i: Potion.cpp.i
.PHONY : Potion.i

# target to preprocess a source file
Potion.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Potion.cpp.i
.PHONY : Potion.cpp.i

Potion.s: Potion.cpp.s
.PHONY : Potion.s

# target to generate assembly for a file
Potion.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Potion.cpp.s
.PHONY : Potion.cpp.s

Weapon.o: Weapon.cpp.o
.PHONY : Weapon.o

# target to build an object file
Weapon.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Weapon.cpp.o
.PHONY : Weapon.cpp.o

Weapon.i: Weapon.cpp.i
.PHONY : Weapon.i

# target to preprocess a source file
Weapon.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Weapon.cpp.i
.PHONY : Weapon.cpp.i

Weapon.s: Weapon.cpp.s
.PHONY : Weapon.s

# target to generate assembly for a file
Weapon.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Weapon.cpp.s
.PHONY : Weapon.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... rebuild_cache"
	@echo "... Actors.o"
	@echo "... Actors.i"
	@echo "... Actors.s"
	@echo "... Armor.o"
	@echo "... Armor.i"
	@echo "... Armor.s"
	@echo "... Console.o"
	@echo "... Console.i"
	@echo "... Console.s"
	@echo "... Enemy.o"
	@echo "... Enemy.i"
	@echo "... Enemy.s"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... Hero.o"
	@echo "... Hero.i"
	@echo "... Hero.s"
	@echo "... Item.o"
	@echo "... Item.i"
	@echo "... Item.s"
	@echo "... Point2d.o"
	@echo "... Point2d.i"
	@echo "... Point2d.s"
	@echo "... Potion.o"
	@echo "... Potion.i"
	@echo "... Potion.s"
	@echo "... Weapon.o"
	@echo "... Weapon.i"
	@echo "... Weapon.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

# Makefile for RShell

# Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

# Targets
all: ~/rshell/src/exec.cpp
	mkdir ~/rshell/bin
	$(COMPILE) $(FLAGS) ~/rshell/src/exec.cpp -o ~/rshell/bin/rshell

rshell: ~/rshell/src/exec.cpp
	$(COMPILE) $(FLAGS) -o rshell ~/rshell/src/exec.cpp

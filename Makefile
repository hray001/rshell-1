# Makefile for RShell

# Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

# Targets
all: ~/rshell/src/exec.cpp
	mkdir ~/bin
	$(COMPILE) $(FLAGS) ~/rshell/src/exec.cpp -o ~/bin/rshell

rshell: ~/rshell/src/exec.cpp
	$(COMPILE) $(FLAGS) -o rshell ~/rshell/src/exec.cpp

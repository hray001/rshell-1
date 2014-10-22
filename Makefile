# Makefile for RShell

# Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

# Targets
all: ~/rshell/src/exec.cpp
	$(COMPILE) $(FLAGS) ~/rshell/src/exec.cpp

rshell: ~/rshell/src/exec.cpp
	$(COMPILE) $(FLAGS) exec.cpp -o rshell

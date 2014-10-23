# Makefile for RShell

# Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

# Targets
all: ./src/exec.cpp
	mkdir ./bin
	$(COMPILE) $(FLAGS) ./src/exec.cpp -o ./bin/rshell

rshell: ./src/exec.cpp
	$(COMPILE) $(FLAGS) -o rshell ./src/exec.cpp

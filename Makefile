# Makefile for RShell

# Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

# Targets
all: cp
	mkdir ./bin
	$(COMPILE) $(FLAGS) ./src/exec.cpp -o ./bin/rshell

#rshell: ./src/exec.cpp
#	$(COMPILE) $(FLAGS) -o rshell ./rshell/src/exec.cpp
cp: ./src/cp.cpp
	$(COMPILE) $(FLAGS) ./src/cp.cpp -o cp

# Makefile for RShell

# Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

# Targets
all: ./src/exec.cpp ./src/ls.cpp
	mkdir ./bin
	$(COMPILE) $(FLAGS) ./src/exec.cpp -o ./bin/rshell
	$(COMPILE) $(FLAGS) ./src/ls.cpp -o ./bin/ls

ls: ./src/ls.cpp
	$(COMPILE) $(FLAGS) ./src/ls.cpp -o ls

rshell: ./src/exec.cpp
	$(COMPILE) $(FLAGS) -o rshell ./src/exec.cpp

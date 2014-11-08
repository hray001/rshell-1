# Makefile for RShell

# Variables
COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

# Targets
all: ls rshell clean 
	mkdir ./bin
	$(COMPILE) $(FLAGS) ./src/exec.cpp -o ./bin/rshell
	$(COMPILE) $(FLAGS) ./src/ls.cpp -o ./bin/ls

ls: ./src/ls.cpp
	$(COMPILE) $(FLAGS) ./src/ls.cpp -o ls

rshell: ./src/exec.cpp
	$(COMPILE) $(FLAGS) ./src/exec.cpp -o rshell

clean:
	rm -rf ./bin


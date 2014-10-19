// Maintainer: Jan Kristian Sto. Domingo [jstod001@ucr.edu]
// exec.cpp for rshell

#include <iostream>
#include <string>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

//Notes on function formats:
//execvp(const char *file, char *const argv[])

int main()
{
    int PID = fork();
    if(PID == 0)
    {
        cout << "child process" << endl;
        
        string input;

        cout << "$ ";
        getline(cin, input);
        input.c_str();      //converts string into a cstring

        // testing
        cout << "Test string: " << input << endl << endl;

        // execvp(argv[0], argv);

    }
    else
    {
        wait(0);
        cout << "parent process" << endl;
    }

    return 0;
}


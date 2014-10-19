// Maintainer: Jan Kristian Sto. Domingo [jstod001@ucr.edu]
// exec.cpp for rshell

#include <iostream>
#include <cstring>
#include <string>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
        
        string str_input;
        cout << "$ ";           //serves as command prompt
        getline(cin, str_input);

        cout << "Original string: " << str_input << endl << endl;

        char* c_input = new char[str_input.length() + 1];
        strcpy(c_input, str_input.c_str());

        cout << "Converted to cstring: " << c_input << endl << endl;
        
        /*
        char **token;
        token = strtok(c_input, " ");
        while(token != NULL)
        {
            token = strtok(NULL, " ");
        }
        */

        // testing
        // cout << "Test c_string: " << c_input << endl << endl;

        // new cstring now has to be tokenized and placed into a char**
        // for the exec vp function

        // execvp(argv[0], argv);

    }
    else
    {
        wait(0);
        cout << "parent process" << endl;
    }

    return 0;
}


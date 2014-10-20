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

// tokenCounter function used to determine size of dynamically
// allocated array for use in the execvp function
unsigned tokenCounter(char* a)
{
    unsigned count = 0;
    char* token;

    token = strtok(a, " ;");

    while(token != NULL)
    {
        token = strtok(NULL, " ;");
        count++;
    }

    return count;
}

int main()
{
    int PID = fork();
    if(PID == 0)
    {
        //cout << "child process" << endl;
        
        // command prompt
        char* username = getlogin();
        char hostname[10];
        gethostname(hostname, 10);
        cout << username << "@" << hostname;
        cout << "$ ";
        
        string str_input;
        getline(cin, str_input);

        // output message for test purposes
        // cout << "Original string: " << str_input << endl << endl;

        char* c_input = new char[str_input.length() + 1];
        strcpy(c_input, str_input.c_str());

        // output message for test purposes
        // cout << "Converted to cstring: " << c_input << endl << endl;
        
        // new cstring now has to be tokenized and placed into a char**
        // for the exec vp function

        char* tmp = new char[str_input.length() + 1];
        strcpy(tmp, c_input);
        // tmp protects the original cstring input
        // tmp will be used for the tokenCounter function

        unsigned token_count = 0;
        token_count = tokenCounter(tmp);

        char** arg;
        arg = new char* [token_count];
        
        // output message for test purposes
        // cout << "c_input after tokenCounter: " << c_input << endl;

        // the following chunk of code will take each token and place it into arg
        // which will then be used as a parameter in execvp
        unsigned i = 0;
        char* ptr;
        ptr = strtok(c_input, " ;");
        while(ptr != NULL)
        {
            arg[i] = ptr;
            ptr = strtok(NULL, " ;");
            i++;
        }

        //cout << arg[0] << endl;
        execvp(arg[0], arg);
        perror(arg[0]);
    }
    else
    {
        if(PID == -1)
        {
            perror("fork");
        }
        int w = wait(0);
        if(w == -1)
        {
            perror("wait");
        }
        //cout << "parent process" << endl;
    }

    return 0;
}


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
//#include <boost/tokenizer.hpp>

using namespace std;
//using namespace boost;

//Notes on function formats:
//execvp(const char *file, char *const argv[])

// tokenCounter function used to determine size of dynamically
// allocated array for use in the execvp function
unsigned tokenCounter(char* a)
{
    unsigned count = 0;
    char* token;

    token = strtok(a, " ;&|#");

    while(token != NULL)
    {
        token = strtok(NULL, " ;&|#");
        count++;
    }

    return count;
}

int main()
{
    string str_input = "";
    do
    {
        cout << "\t<child process>" << endl;
        
        // command prompt
        char* username = getlogin();
        char hostname[20];
        gethostname(hostname, 20);
        cout << username << "@" << hostname << "$ ";
        
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
        arg = new char* [token_count + 1];
        
        // output message for test purposes
        // cout << "c_input after tokenCounter: " << c_input << endl;

        
        // the following chunk of code will take each token
        // and place it into arg which will then be used as
        // a parameter in execvp
        unsigned i = 0;
        char* ptr;
        ptr = strtok(c_input, " ;&#|");
        while(ptr != NULL)
        {
            arg[i] = ptr;
            // cout message for test purposes
            cout << "arg[" << i << "] = " << arg[i] << endl;
            // cout << "arg[" << i << "] length = " << strlen(arg[i]) << endl;
            ptr = strtok(NULL, " ;&#|");
            i++;
        }
        arg[i] = '\0';
        

        /*
        char_separator<char> separ(" ;&|");
        tokenizer<char_separator<char> > token_list(str_input, separ);
        */

        //cout << arg[0] << endl;
        if(string(arg[0]) == "exit")
        {
            //cout message for test purposes
            cout << "\t<executing exit(0)>" << endl;
            exit(0);
        }

        int PID = fork();
        if(PID == 0) 
        {
            //cout message for test purposes
            cout << "\t<in execvp>" << endl;
            int exec = execvp(arg[0], arg);
            perror(arg[0]);
            if(exec == -1)
            {
                exit(0);
            }
        }
        else
        {
            if(PID == -1)
            {
                perror("fork failed");
            }
            int w = wait(0);
            if(w == -1)
            {
                perror("wait");
            }
            cout << "\t<parent process>" << endl;
        }
    }while(str_input != "exit");
    cout << "after do-while" << endl;
/*
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
*/
    return 0;
}


#include <cstring>
#include <iostream>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>

using namespace std;

// ===================
// Function Prototypes
// ===================

void build_list(vector<char*> &list, bool a);    // builds the file list vector
void sort_list(vector<char*> &list, bool a);     // sorts the vector containing the file names
void ls(bool a);                                 // outputs the file list

// =============
// Main Function
// =============

int main(int argc, char** argv)
{
    // bool variables will check if flags are passed in
    //bool a, l, R = 0;
    vector<char*> list(0);
    bool a = 1;
    cout << "| ls test |" << endl;
    build_list(list, a);

    for(unsigned i = 0; i < list.size(); i++)
    {
        cout << list.at(i) << "  ";
    }

    cout << endl;

    return 0;
}

// =====================
// Function Declarations
// =====================

void sort_list(vector<char*> &list, bool a)
{
    // vector containing the files should be alphabetically sorted
    // format (for ls -a): . .. file1.asm file1.cpp... etc
    // regular files in ls -a have precedence over hidden files
    // in alphabetical order (a comes before .a)
    
    // Possible algorithm:
    // search for '.' and ".."
    // place them in positions 0 and 1, respectively
    // after that, alphabetically sort the names within the vector
    // following the above notes
    
    const char period[2] = ".";
    const char dbl_period[3] = "..";
    if(a)
    {
        // searches for '.' and ".."
        // places them in positions 0 and 1
        for(unsigned i = 0; i < list.size(); i++)
        {
            if(strcmp(list.at(i), period) == 0)
            {
                char* temp1 = list.at(0);
                list.at(0) = list.at(i);
                list.at(i) = temp1;
            }
            else if(strcmp(list.at(i), dbl_period) == 0)
            {
                char* temp2 = list.at(1);
                list.at(1) = list.at(i);
                list.at(i) = temp2;
            }
        }

        // After that, the rest of the files are sorted in alphabetical order
        // Starts at position 2 because position 0 and 1 are already sorted
        for(unsigned i = 2; i < list.size() - 1; i++)
        {
            for(unsigned j = i; j < list.size(); j++)
            {
                
            }
        }
    }

    else
    {

    }
}

void build_list(vector<char*> &file_list, bool a)
{
    const char* directoryName = ".";
    DIR* dir_point = opendir(directoryName);

    if(dir_point == NULL)
        perror("opendir");
    
    dirent* dirent_p;

    if(a) // case for -a flag; adds all files to list
    {
        while((dirent_p = readdir(dir_point)))
        {
            if(dirent_p == NULL)
                perror("readdir");
            
            file_list.push_back(dirent_p->d_name);
        }
    }

    else // case for no passed in flags; adds only visible files
    {
        while((dirent_p = readdir(dir_point)))
        {
            if(dirent_p == NULL)
                perror("readdir");
            
            if(dirent_p->d_name[0] != '.')
                file_list.push_back(dirent_p->d_name);
        }
    }

    //FIXME: Once all of the files have been stored in the vector,
    //they must be sorted in alphabetical order
    
    sort_list(file_list, a);

    int close_status = closedir(dir_point);
    if(close_status == -1)
        perror("closedir");
}


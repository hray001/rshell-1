#include <iostream>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

void ls_all() //function for ls -a
{
    const char* directoryName = ".";
    DIR* dir_point = opendir(directoryName);

    if(dir_point == NULL)
        perror("opendir");
    
    dirent* dirent_p;

    while((dirent_p = readdir(dir_point)))
    {
        if(dirent_p == NULL)
            perror("readdir");
        cout << dirent_p->d_name << endl;   // outputs the name of the file
    }

    int close_status = closedir(dir_point);
    if(close_status == -1)
        perror("closedir");
}

int main(int argc, char** argv)
{
    ls_all();

    return 0;
}

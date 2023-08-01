//Program which create new process which is responsible to write all the file names which are present on desktop in demo file which should be created newly.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid;
    int status;
    
    pid = fork();
    
    if(pid == 0)
    {
        execl("./Demo","NULL",NULL);
    }
    else
    {
        wait(&status);
    }
    
    return 0;
}

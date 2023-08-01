//Program in which parent process waits till its child process terminates
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid, status;
    
    pid = fork();
    
    if(pid == 0)
    {
        printf("Child Process.\n");
    }
    else
    {
        wait(&status);
        printf("Parent Process");
    }
    
    return 0;
}

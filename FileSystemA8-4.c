//Program in which parent process waits till 2 process terminates
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid, pid1;
    int status;
    
    pid = fork();
    
    if(pid == 0)
    {
       // printf("Child Process 1 Pid : %d",getpid());
        execl("./ChildProcess1",NULL,NULL);
    }
    
    pid1 = fork();
    if(pid1 == 0)
    {
        //printf("Child Process 2 Pid : %d",getpid());
        execl("./ChildProcess2",NULL,NULL);
    }
    else
    {
        printf("Parent Process");
        wait(&status);
    }
    
    return 0;
    
}

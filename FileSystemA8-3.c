//Program in which parent process creates 3 different process.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid, pid1, pid2;
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
    pid2 = fork();
    if(pid2 == 0)
    {
        //printf("Child Process 3 Pid : %d",getpid());
        execl("./ChildProcess3",NULL,NULL);
    }
    else
    {
        wait(&status);
    }
    
    return 0;
    
}

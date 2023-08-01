//Program which used to print priority of process
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid;
    int pr, p;
    int status;
    
    pid = fork();
    
    if(pid == 0)
    {
        p = getpid();
        pr = getpriority(PRIO_PROCESS,p);
        printf("priority : %d",pr);
    }
    else
    {
        wait(&status);
    }
    
    return 0;
}

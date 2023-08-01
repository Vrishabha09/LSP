//Program which used to print priority of process
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid;
    int newp;
    int pr, p;
    int status;
    
    pid = fork();
    
    if(pid == 0)
    {
        p = getpid();
        pr = getpriority(PRIO_PROCESS,p);
        printf("priority : %d\n",pr);
        newp = pr - 5;
        setpriority(PRIO_PROCESS,p,newp);
        printf("new priority : %d\n",newp);
    }
    else
    {
        wait(&status);
    }
    
    return 0;
}

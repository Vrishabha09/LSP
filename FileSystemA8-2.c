//Program in which parent process waits till its child process terminates
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid, pid1, pid2;
    
    pid = fork();
    
    if(pid == 0)
    {
        printf("Child Process 1 with pid : %d.\n",getpid());
        
        pid1 = fork();
        if(pid1 == 0)
        {
            printf("Child Process 2 with pid : %d.\n",getpid());
            pid2 = fork();
            if(pid2 == 0)
            {
                printf("Child Process 3 with pid : %d.\n",getpid());
            }
            else
            {
                printf("Parent Process of Child 3 : %d\n",getpid());
            }
        }
        else
        {
            printf("Parent Process of Child 2 : %d\n",getpid());
        }
    }
    else
    {
        printf("Parent Process of Child 1 : %d\n",getppid());
    }
    return 0;
}

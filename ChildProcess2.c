#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("Child Process 2 Pid : %d\n",getpid());
    return 0;
}

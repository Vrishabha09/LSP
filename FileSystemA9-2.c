//Program which create 2 process ,process 1 count capital letters in demo.txt and process 2 count capital letters from hello.txt
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid,pid1;
    int status;
    
    pid = fork();
    
    if(pid == 0)
    {
        execl("./A9-2_1","NULL",NULL);
    }
    pid1 = fork();
    
    if(pid1 == 0)
    {
        execl("./A9-2_2","NULL",NULL);
    }
    else
    {
        wait(&status);
    }
    
    return 0;
}

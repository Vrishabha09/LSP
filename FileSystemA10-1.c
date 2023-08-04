//Program to create simple thread by using pthread library.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
    printf("Inside Thread.\n");
}
int main()
{
    int iRet = 0;
    pthread_t TID;
    
    iRet = pthread_create(&TID,NULL,ThreadProc,NULL);
    
    if(iRet != 0)
    {
        printf("Unable to create thread.\n");
        return -1;
    }
    
    printf("Thread is created with ID : %d.\n",TID);
              
    return 0;
}

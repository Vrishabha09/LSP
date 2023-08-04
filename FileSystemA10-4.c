//Program to create simple thread by using pthread library, and thread will accept value from user and return it to caller thread.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
    int iNo = 0;
    
    printf("Enter no : ");
    scanf("%d",&iNo);
    
    pthread_exit(iNo);
}
int main()
{
    int iRet = 0,value = 0;
    
    pthread_t TID1;
    
    iRet = pthread_create(&TID1,NULL,ThreadProc,NULL);
    
    if(iRet != 0)
    {
        printf("Unable to create thread.\n");
        return -1;
    }
    
    printf("Thread 1 is created with ID : %d.\n",TID1);
    pthread_join(TID1,&value);
    printf("Value recieved from thread 1 : %d.\n",value);
    
    printf("End od main thread.\n");
    return 0;
}

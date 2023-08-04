//Program to create simple thread by using pthread library, and pass parameter from main thread.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
    printf("Value recieved from main thread : %d.\n",(int)ptr);
}
int main()
{
    int iRet = 0;
    int iNo = 0;
    pthread_t TID1;
    
    printf("Enter no : ");
    scanf("%d",&iNo);
    
    iRet = pthread_create(&TID1,NULL,ThreadProc,(int *)iNo);
    
    if(iRet != 0)
    {
        printf("Unable to create thread.\n");
        return -1;
    }
    
    printf("Thread 1 is created with ID : %d.\n",TID1);
    pthread_join(TID1,NULL);
    
    printf("End od main thread.\n");
    return 0;
}

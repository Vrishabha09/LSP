//Program to create simple thread by using pthread library which is used to get thread id inside its thread function.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
    int iNo = 0;
    
    iNo = pthread_self();
    
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
    
    printf("Thread 1 ID in main thread = %d.\n",TID1);
    pthread_join(TID1,&value);
    printf("Thread id recieved from thread 1 = %d.\n",value);
    
    printf("End of main thread.\n");
    return 0;
}

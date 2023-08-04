//Program to create 2 thread by using pthread library, one will printf 1 - 500, and other will print 500 - 1.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc1(void *ptr)
{
    for(int i = 1; i <= 500; i++)
    {
        printf("%d\n",i);
    }
}
void *ThreadProc2(void *ptr)
{
    for(int i = 500; i > 0; i--)
    {
        printf("%d\n",i);
    }
}
int main()
{
    int iRet = 0, iRet1 = 0;
    pthread_t TID1;
    pthread_t TID2;
    
    iRet = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    
    if(iRet != 0)
    {
        printf("Unable to create thread.\n");
        return -1;
    }
    
    printf("Thread 1 is created with ID : %d.\n",TID1);
    pthread_join(TID1,NULL);
    
    iRet1 = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    
    if(iRet1 != 0)
    {
        printf("Unable to create thread.\n");
        return -1;
    }
    
    printf("Thread 2 is created with ID : %d.\n",TID2);
    pthread_join(TID2,NULL);
    
    printf("End od main thread.\n");
    return 0;
}

#include<stdio.h>
#include"A7.h"

float Addition(float a, float b)
{
    float iAns = 0.00f;
    
    iAns = a + b;
    return iAns;
}

float Sub(float a, float b)
{
    float iAns = 0.00f;
    
    iAns = a - b;
    return iAns;
}

float Div(float a, float b)
{
    float iAns = 0.00f;
    
    iAns = a / b;
    return iAns;
}

float Mult(float a, float b)
{
    float iAns = 0.00f;
    
    iAns = a * b;
    return iAns;
}

int Accept(int fd,int fd1)
{
    int Ret = 0;
    char Buffer[1024];
    char Buffer1[1024];
    struct stat sobj;
    struct stat sobj1;
    
    fstat(fd,&sobj);
    fstat(fd1,&sobj1);
    
    if(sobj.st_size != sobj1.st_size)
    {
        printf("Files are not equal.\n");
        return -1;
    }
    
    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        Ret = read(fd1,Buffer1,sizeof(Buffer1));
        if(memcmp(Buffer,Buffer1,Ret) != 0)
        {
            break;
        }
    }
    
    return Ret;
}

void Prime(int iNo)
{
    for(int i = 2; i < iNo/2; i++)
    {
        if((i % iNo) == 0)
        {
            printf("%d is not a prime number .\n",iNo);
        }
        else
        {
            printf("%d is a prime number.\n",iNo);
        }
    }
}

int CallInside(int iNo)
{
    void *ptr2 = NULL;
    int Ret = 0;
    int iNum = iNo;
    
    ptr2 = dlopen("library1.so",RTLD_LAZY);
    
    if(ptr2 == NULL)
    {
        printf("Failed to load Inside library.\n");
        return -1;
    }
    
    int (*fptr2)(int) = (int (*)(int))dlsym(ptr2,"Factorial");
    
    if(fptr2 == NULL)
    {
        printf("Unable to load address of inside library");
        return -1;
    }
    
    Ret = fptr2(iNum);
    
    return 0;
}

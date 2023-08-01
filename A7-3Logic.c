//Second lib perfect number/ Factorial
#include<stdio.h>
#include"A7.h"

void Perfect(int iNo)
{
    int iSum = 0;
    
    for(int i = 1; i < iNo; i++)
    {
        if((i % iNo) == 0)
        {
            iSum = iSum + i;
        }
    }
    if(iSum == iNo)
    {
        printf("%d is a Perfect number.\n",iNo);
    }
    else
    {
        printf("%d is not a Perfect number.\n",iNo);
    }
}

int Factorial(int iNum)
{
    int iSum = 1;
    
    for(int i = 1; i <= iNum; i++)
    {
        iSum *= i;
    }
    
    printf("Factorial of %d is : %d.\n",iNum,iSum);
     
    return 0;
}


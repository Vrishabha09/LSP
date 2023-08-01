//Program which uses shared library that performs arithmetic operations like +,-,*,/
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    //void (*fptr)();
    float iNo = 0.0f, iNo1 = 0.0f;
    
    ptr = dlopen("Library.so",RTLD_LAZY);
    
    if(ptr == NULL)
    {
        printf("Unable to load library.\n");
        return -1;
    }
    printf("Enter first number : ");
    scanf("%f",&iNo);
    
    printf("Enter second number : ");
    scanf("%f",&iNo1);
    
    //typecast
    float (*fptr)(float,float) = (float (*)(float, float))dlsym(ptr,"Addition");
    float (*fptr1)(float,float) = (float (*)(float, float))dlsym(ptr,"Sub");
    float (*fptr2)(float,float) = (float (*)(float, float))dlsym(ptr,"Div");
    float (*fptr3)(float,float) = (float (*)(float, float))dlsym(ptr,"Mult");
    
    if(fptr == NULL)
    {
        printf("Unable to load the address library.\n");
        return -1;
    }
    
    //int iRet = Addition(iNo,iNo1);
    
    float iRet = fptr(iNo,iNo1);
    printf("Addition is : %2.f\n",iRet);
    
    iRet = fptr1(iNo,iNo1);
    printf("Substraction is : %2.f\n",iRet);
    
    iRet = fptr2(iNo,iNo1);
    printf("Division is : %2.f\n",iRet);
    
    iRet = fptr3(iNo,iNo1);
    printf("Multiplication is : %2.f\n",iRet);
    
    return 0;
}

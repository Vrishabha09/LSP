//Program to create 2 shared libraries and the 1st library function checks whether the input number is prime or not and 2nd library checks whether the input number is perfect or not
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    int iNo = 0;
    
    void *ptr = NULL;
    void *ptr1 = NULL;
    
    ptr = dlopen("library.so",RTLD_LAZY);
    ptr1 = dlopen("library1.so",RTLD_LAZY);
    
    if((ptr == NULL) &&(ptr1 == NULL))
    {
        printf("Unable to load the library.\n");
        return -1;
    }
    
    void (*fptr)(int) = (int (*)(int))dlsym(ptr,"Prime");
    void (*fptr1)(int) = (int (*)(int))dlsym(ptr1,"Perfect");
    
    if((fptr == NULL) && (fptr1 == NULL))
    {
        printf("Unable to load the address of the library.\n");
        return -1;
    }
    
    printf("Enter no : ");
    scanf("%d",&iNo);
    
    fptr(iNo);
    fptr1(iNo);
    
    return 0;
}

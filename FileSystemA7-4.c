//Program to load a shared library which loads another shared library inside it which will have function to cal factorial of a number.
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    int iNo = 0;
    
    void *ptr = NULL;
    
    ptr = dlopen("library.so",RTLD_LAZY);
    
    if(ptr == NULL)
    {
        printf("Unable to load the library.\n");
        return -1;
    }
    
    int (*fptr)(int) = (int (*)(int))dlsym(ptr,"CallInside");
    
    if(fptr == NULL)
    {
        printf("Unable to load the address of the library.\n");
        return -1;
    }
    
    printf("Enter no : ");
    scanf("%d",&iNo);
    
    int Ret = fptr(iNo);
    
    return 0;
}

//Program that uses shared library which contains function which tells us that 2 files are identical or not
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = -1, fd1 = -1;
    int Ret = -1;
    void *ptr = NULL;
    char Fname[20],Fname1[20];
    
    ptr = dlopen("Library.so",RTLD_LAZY);
    
    if(ptr == NULL)
    {
        printf("Unable to load library.\n");
        return -1;
    }
    
    printf("Enter first file name : ");
    scanf("%s",Fname);
    
    printf("Enter second file name : ");
    scanf("%s",Fname1);
    
    int (*fptr)(int, int) =(int (*)(int,int)) dlsym(ptr,"Accept");
    if(fptr == NULL)
    {
        printf("Unable to load the address library.\n");
        return -1;
    }
    fd = open(Fname,O_RDONLY);
    fd1 = open(Fname1,O_RDONLY);
    if((fd == -1) || (fd1 == -1))
    {
        printf("Unable to open files.\n");
        return -1;
    }
    Ret = fptr(fd,fd1);
    if (Ret == 0)
    {
        printf("Both files are identical.\n");
    } else
    {
        printf("Both files are not identical.\n");
    }
    
    close(fd);
    close(fd1);
    
    return 0;
}

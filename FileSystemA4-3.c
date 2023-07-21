//Program to accept two file names from user and check whether contents of that files are equal or not.
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, Ret = 0;
    struct stat sobj1, sobj2;
    char Buffer1[1024];
    char Buffer2[1024];
    char Fname1[20] = {'\0'};
    char Fname2[20] = {'\0'};
    
    printf("Enter first file name : ");
    scanf("%s",Fname1);
    
    printf("Enter second file name : ");
    scanf("%s",Fname2);
    
    fd1 = open(Fname1,O_RDONLY);
    fd2 = open(Fname2,O_RDONLY);
    
    if((fd1 == -1) && (fd2 == -1))
    {
        printf("Unable to open files.\n");
        return -1;
    }
    
    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);
    
    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are not identical.\n");
        close(fd1);
        close(fd2);
        return -1;
    }
    
    while((Ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,Ret) != 0)
        {
            break;
        }
    }
    if (Ret == 0)
    {
        printf("Both files are identical.\n");
    } else
    {
        printf("Both files are not identical.\n");
    }
    
    close(fd1);
    close(fd2);
    
    return 0;
}

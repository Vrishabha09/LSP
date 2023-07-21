//Program to accept file name from user and write string in that file
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    struct stat sobj;
    char str[50] = {'\0'};
    int Ret = 0;
    
    if(argc != 2)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    printf("Enter the string you want to enter : ");
    scanf("%s",&str);
    
    fd = open(argv[1],O_RDWR);
    fstat(fd,&sobj);
    
    if(fd == -1)
    {
        printf("Unable to open file");
        return -1;
    }
    else
    {
        if(sobj.st_size == 0)
        {
            write(fd,str,sizeof(str));
        }
        else
        {
            lseek(fd,sobj.st_size,0);
            write(fd,str,sizeof(str));
        }
    }
    return 0;
}


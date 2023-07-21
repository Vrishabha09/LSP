//Program to accept two file names from user and copy the contents of an existing file into newly created file.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE];
    
    if(argc != 3)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    
    fd1 = open(argv[1],O_RDONLY);
    fd2 = creat(argv[2],0777);
    
    if((fd1 == -1) && (fd2 == -1))
    {
        printf("Unable to open or create file.\n");
        return -1;
    }
    while((Ret = read(fd1, Buffer , sizeof(Buffer))) != 0)
    {
        write(fd2,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));
    }
    
    close(fd1);
    close(fd2);
    
    return 0;
}

//Program to accpet file name and mode from user and open that file in that mode.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int mode = 0;
    if(argc != 3)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    
    if(strcmp(argv[2],"Read") == 0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"ReadWrite") == 0)
    {
        mode = O_RDWR;
    }
    else
    {
        printf("Invalid mode , couldn't open file.\n");
        return -1;
    }
    
    fd = open(argv[1],mode);
    
    if(fd == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }
    else
    {
        printf("File openedc succesfully with fd %d and mode: %s.\n",fd,argv[2]);
    }
    printf("%d",mode);
    return 0;
}

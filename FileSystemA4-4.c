//Program to accept a directory name from user and copy first 10 bytes from all regular files into newly created file named as Demo.txt
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    int size = 10;
    char Buffer[size];
    int Ret = 0;
    struct dirent *entry = NULL;
    struct stat sobj;
    int fd = 0, fd1 = 0;
    char path1[50];
    
    if(argc != 3)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    sprintf(path1,"%s/%s",argv[1],argv[2]);
    fd = creat(path1,O_RDWR);
    
    if(fd == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory.\n");
        return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        char path[50];
        stat(entry->d_name,&sobj);
        sprintf(path,"%s/%s",argv[1],entry->d_name);
        if(S_ISREG(sobj.st_mode))
        {
            fd1 = open(path,O_RDONLY);
            if(fd1 == -1)
            {
                printf("Unable to open file.\n");
                return -1;
            }

            Ret = read(fd1,Buffer,size);
            write(fd,Buffer,Ret);
        }
    }
    closedir(dp);
    close(fd);
    close(fd1);
    return 0;
}

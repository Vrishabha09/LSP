//Program to accept directory name and file name and check whether that file is present in that directory or not.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<stdbool.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    bool Flag = false;
    
    if(argc != 3)
    {
        printf("Insufficient Arguenments.\n");
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
        if((strcmp(entry->d_name,argv[2])) == 0)
        {
            Flag = true;
            break;
        }
    }
    
    if(Flag == true)
    {
        printf("File %s is present in %s directory.\n",argv[2],argv[1]);
    }
    else
    {
        printf("File %s not present in %s directory.\n",argv[2],argv[1]);
    }
    return 0;
}

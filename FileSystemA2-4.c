//Program to accept directory name and print all file names and its type from that directory
#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct stat sobj;
    struct dirent *entry = NULL;
    
    if(argc != 2)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    
    dp = opendir(argv[1]);
    
    if(dp == NULL)
    {
        printf("Unable to open directory.\n");
        return -1;
    }
    
    printf("Entries from directory %s are .\n",argv[1]);
    printf("-----------------------------------------\n");
    
    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("File Name : %s \t| Mode : Regular File.\n",entry->d_name);
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("File Name : %s \t| Mode : Directory.\n",entry->d_name);
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("File Name : %s \t| Mode : Symbolic link.\n",entry->d_name);
        }
        else
        {
            printf("File name : %s \t| Mode : Other.\n",entry->d_name);
        }
    }
    printf("-----------------------------------------\n");
    closedir(dp);
    
    return 0;
}

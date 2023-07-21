//Program to accept a directory name and delete all empty files
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    char path[50] = {'\0'};
    struct dirent *entry = NULL;
    struct stat sobj;
    
    if(argc != 2)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directiory.\n");
        return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name,&sobj);
        if(sobj.st_size == 0)
        {
            sprintf(path,"%s/%s",argv[1],entry->d_name);
            remove(path);
            printf("Deleted : %s\n",path);
        }
    }
    closedir(dp);
    return 0;
}

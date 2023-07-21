//Program to accept directory name and print file name which has maximum size in that directory
#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int iMax = 0;
    
    DIR *dp = NULL;
    char Dname[20] = {'\0'};
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
    
    printf("Largest file in %s directory is : ",argv[1]);
    
    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(Dname,entry->d_name);
            }
        }
    }
    printf("%s with size %d bytes",Dname,iMax);
    return 0;
}

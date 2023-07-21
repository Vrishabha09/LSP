//Program to accept directory name and print all file names from that directory
#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
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
        printf("%s \n",entry->d_name);
    }
    printf("-----------------------------------------\n");
    
    return 0;
}

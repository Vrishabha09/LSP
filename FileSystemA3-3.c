//Program to accept two directory name source and destination and move source files into destination directory.
#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *source = NULL;
    DIR *dest = NULL;
    int iMake = -1;
    char Spath[50] = {'\0'};
    char Dpath[50] = {'\0'};
    struct dirent *entry = NULL;
    
    if(argc != 3)
    {
        printf("Insufficient Arguements.\n");
        return -1;
    }
    
    source = opendir(argv[1]);
    iMake = mkdir(argv[2],S_IRWXU | S_IRWXG | S_IRWXO);
    
    if((source == NULL) && (iMake == -1))
    {
        printf("Failed to open %s directory or create %s directory.\n",argv[1],argv[2]);
        return -1;
    }
    
    while((entry = readdir(source)) != NULL)
    {
        sprintf(Spath,"%s/%s",argv[1],entry->d_name);
        sprintf(Dpath,"%s/%s",argv[2],entry->d_name);
        rename(Spath,Dpath);
    }
    
    closedir(source);
    closedir(dest);
    return 0;
}

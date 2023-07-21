//Program to accept a directory name from and user and create new directory of that name.
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char Dname[20] = {'\0'};
    
    printf("Enter directory name : ");
    scanf("%s",Dname);
    
    dp = opendir(".");
    if(dp == NULL)
    {
        printf("Unable to open current directory.\n");
        return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name,&sobj);
        if(S_ISDIR(sobj.st_mode))
        {
            if((strcmp(entry->d_name,Dname)) == 0)
            {
                printf("Unable to create directory %s as a directory of that name exists.\n",Dname);
                closedir(dp);
            }
            else
            {
                if((mkdir(Dname,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)) != 0)
                {
                    printf("Unable to create diretory.\n");
                    closedir(dp);
                    return -1;
                }
                else
                {
                    printf("%s directory created successfully.\n",Dname);
                    break;
                }
            }
        }
    }
    closedir(dp);
    return 0;
}

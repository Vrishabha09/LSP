//Program which accept file name from user and print all information about that file.
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    struct stat sobj;
    
    if(argc != 2)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    
    fd = open(argv[1],O_RDONLY);
    fstat(fd,&sobj);
    
    if(fd == -1)
    {
        printf("Unable to open file .\n");
        return -1;
    }
    else
    {
        printf("-------------------File information---------------------\n");
        printf("File Name : %s.\n",argv[1]);
        printf("Inode number : %d.\n",sobj.st_ino);
        printf("File System number : %d.\n", sobj.st_dev);
        printf("User id of the file owner : %d.\n",sobj.st_uid);
        printf("Group id of the file : %d.\n",sobj.st_gid);
        printf("File status change time : %s\n",ctime(&sobj.st_ctime));
        printf("File last accessed at : %s\n",ctime(&sobj.st_atime));
        printf("File last modified : %s\n", ctime(&sobj.st_mtime));
        printf("Number of links : %d.\n",sobj.st_nlink);
        printf("Number of blocks : %d.\n", sobj.st_blocks);
        printf("--------------------------------------------------------");
    }
    return 0;
}

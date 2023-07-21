//Program to accept name and position from user and read 20 bytes from that position.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int pos = 0;
    int Ret = 0;
    char Fname[20];
    char Buffer[20];
    
    printf("Enter the file name : ");
    scanf("%s",Fname);
    
    printf("Enter position : ");
    scanf("%d",&pos);
    
    fd = open(Fname,O_RDONLY);
    if(fd == -1)
    {
        printf("unable to open file.\n");
        return -1;
    }
    
    lseek(fd,pos,0);
    
    Ret = read(fd,Buffer,sizeof(Buffer));
    
    printf("Data from the file is : \n");
    write(1,Buffer,Ret);
    
    close(fd);
    return 0;
}

//Program which accept file name from user which contains information,we have to read the contents from that file.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0;
    
    printf("Enter the file name : ");
    scanf("%s",Fname);
    
    fd = open(Fname,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }
    
    read(fd,&sobj,sizeof(sobj));
    
    printf("Roll Number : %d\n",sobj.Rollno);
    printf("Name : %s\n",sobj.Sname);
    printf("Marks : %f\n",sobj.Marks);
    printf("Age : %d\n",sobj.Age);
    return 0;
}


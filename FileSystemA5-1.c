//Program which writes structure in file.Structure should contains information of student
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[30];
    float Marks;
    int Age;
};

int main(int argc,char *argv[])
{
    struct Student sobj;
    char Fname[20];
    char name[20];
    int fd = 0, iNo = 0;
    
    printf("Enter file name : ");
    scanf("%s",Fname);
    
    fd = open(Fname,O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    }
    
    printf("Enter no of students : ");
    scanf("%d",&iNo);
    
    for(int i = 0; i < iNo; i++)
    {
        printf("Enter roll no : ");
        scanf("%d",&sobj.Rollno);
        printf("Enter name : ");
        scanf("%s",name);
        printf("Enter marks: ");
        scanf("%f",&sobj.Marks);
        printf("Enter Age : ");
        scanf("%d",&sobj.Age);
        
        strcpy(sobj.Sname,name);
        
        write(fd,&sobj,sizeof(sobj));
    }
    return 0;
}

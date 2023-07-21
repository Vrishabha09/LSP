//Program to accept file name and mode and check whether our process can access that file in accpeted mode or not.
#include<stdio.h>
//#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int mode = -1;
    int chk = -1;
    
    if(argc != 3)
    {
        printf("Insufficient arguements.\n");
        return -1;
    }
    
    //R_OK = access for reading, W_OK = access for writing, X_OK = access for execusion.
    if(strcmp(argv[2],"Read") == 0)
    {
        mode = R_OK;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        mode = W_OK;
    }
    else
    {
        printf("Invalid mode , couldnt open file in this mode.\n");
        return -1;
    }
//    else if(strcmp(argv[2],"Execute") == 0)
//    {
//        mode = X_OK;
//    }
    
    chk = access(argv[1],mode);
    if(chk == 0)
    {
        printf("Access is given by the process to %s the file.\n",argv[2]);
    }
    else
    {
        printf("Access denied by the process.\n");
    }
    return 0;
}

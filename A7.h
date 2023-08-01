#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dlfcn.h>
#include<string.h>
#include<unistd.h>

float Addition(float a, float b);
float Sub(float a,float b);
float Div(float a, float b);
float Mult(float a, float b);
int Accept(int fd,int fd1);
void Prime(int iNo);
void Perfect(int iNo);
int CallInside(int iNo);
int Fact(int iNum);

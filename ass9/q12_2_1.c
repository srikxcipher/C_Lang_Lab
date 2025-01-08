#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
 char buf[80];
  mkfifo("info.txt",0660);
  int fd=open("info.txt", O_WRONLY);
  write(fd,"ITER\n",5);
  return 0;
  }

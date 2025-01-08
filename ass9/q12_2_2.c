#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
 char buf[80];
  mkfifo("info.txt",0660);
  int fd=open("info.txt", O_RDONLY);
  read(fd,buf,5);
  write(1,buf,5);
  return 0;
  }

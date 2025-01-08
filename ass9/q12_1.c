#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#define BLKSIZE 8
int main()
{
 char buf[80];
 mkfifo("info.txt",0660);
 pid_t p=fork();
 if(p==0){
  int fd=open("info.txt", O_RDONLY);
  read(fd,buf,5);
  write(1,buf,5);
 }
 else{
  int fd=open("info.txt", O_WRONLY);
  write(fd,"CSE-D",5);
 }
  return 0;
  }

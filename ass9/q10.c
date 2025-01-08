#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#define BLKSIZE 8
int main()
{
 char buf[80];
  int fd[2],fs[2],fds[2];
  pipe(fd);
  pid_t pid=fork();
  write(fd[1], "ITER\n",5);
  read(fd[0],buf,5);
  write(1, buf,5); 
  return 0;
 }

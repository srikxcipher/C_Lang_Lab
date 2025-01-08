#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define BLKSIZE 8
int main()
{
 char buf[BLKSIZE];
read(STDIN_FILENO, buf, BLKSIZE);
write(1,buf,8);
return 0;
}

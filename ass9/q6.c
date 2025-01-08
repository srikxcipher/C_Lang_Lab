#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(void)
{
int fd[2],fs[2],fds[2];
pipe(fd);
pipe(fs);
pipe(fds);
while(1);
return 0;
}

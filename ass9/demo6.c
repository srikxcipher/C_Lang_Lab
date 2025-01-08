#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BLKSIZE 80
int main() {
    char buf[BLKSIZE];
    int fd[2];
    pipe(fd);
    write(fd[1], "ITER\n", 5);
    read(fd[0],buf,5);
    write(1,buf,5);
    while(1);
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BLKSIZE 8
int main() {
    int fd[2],fs[2],dfs[2];
    pipe(fd);
    pipe(fs);
    pipe(dfs);
    while(1);
    return 0;
}

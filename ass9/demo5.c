#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BLKSIZE 8
int main() {
    int fd[2];
    pipe(fd);
    pid_t pid=fork();
    if (pid==0){
    printf("Child Process \n");
    }
    else printf("Parent Process \n");
    while(1);
    return 0;
}

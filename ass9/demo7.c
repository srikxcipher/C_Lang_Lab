#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define BLKSIZE 80

///Child writes parent reads .......

int main() {
    char buf[BLKSIZE];
    int fd[2];
    pipe(fd);
    pid_t pid=fork();
    if(pid==0){
    fprintf(stderr,"Child \n");
    close(fd[0]);
    write(fd[1], "ITER\n", 5);
    sleep(5);
    }
    else{
    wait(NULL);
    fprintf(stderr,"Parent \n");
    close(fd[1]);
    read(fd[0],buf,5);
    write(1,buf,5);
    while(1);
    return 0;
}
}

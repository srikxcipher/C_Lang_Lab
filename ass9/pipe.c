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
    pipe(fd); // fd[0] - pipe(read)......fd[1] - pipe(write)
    pid_t pid=fork();
    if(pid==0){
    close(1);  // fd - (1) -> Stdout closed.........
    dup(fd[1]); // pipe(write) --> assigned to lowest fd that becomes available.., i.e fd (1).
    close(fd[0]); // no use so better to close it.
    close(fd[1]); // no use as already copied to stdout.
    execlp("ls","ls",NULL);
    perror("Exec error");
    }
    else{
    close(0);
    dup(fd[0]);
    close(fd[0]);
    close(fd[1]);
    execlp("wc","wc","-l", NULL);
    perror("Parent exec error");
    
    while(1);
    return 0;
}
}

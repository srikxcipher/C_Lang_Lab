#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char buf[40];
    fprintf(stderr, "My PID = %ld\n", (long)getpid());

    int fd, fd1, nb;

    fd = open("q5.c",O_RDONLY);
	while((nb=read(fd,buf,6))!=0){
      write(1,buf,nb);
}
   
	while(1);
    return 0;
}

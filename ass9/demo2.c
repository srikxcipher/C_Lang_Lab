#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BLKSIZE 8
int main() {
    char buf[BLKSIZE];
    
    read(0,buf,8);
    write(1,buf,8);
    return 0;
}

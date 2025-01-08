#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char buf[40];
    fprintf(stderr, "My PID = %ld\n", (long)getpid());

    int fd, fd1, nb;

    // Open DDD.txt for read/write, and create if it doesn't exist
    fd = open("DDD.txt", O_CREAT | O_RDWR, 0660);
    if (fd == -1) {
        perror("Failed to open DDD.txt");
        return 1;
    }

    // Write "ITER is Good\n" to DDD.txt
    write(fd, "ITER is Good\n", 13);

    // Open D1.txt for writing, create if it doesn't exist
    fd1 = open("D1.txt", O_CREAT | O_WRONLY, 0660);
    if (fd1 == -1) {
        perror("Failed to open D1.txt");
        close(fd); // Clean up previously opened file descriptor
        return 1;
    }

    // Read the first 6 bytes of DDD.txt into the buffer
    nb = read(fd, buf, 6);
    if (nb == -1) {
        perror("Failed to read from DDD.txt");
        close(fd);
        close(fd1);
        return 1;
    }

    // Write the first 6 bytes to the standard output (stdout)
    write(1, buf, nb);

    // Write the same 6 bytes to D1.txt
    write(fd1, buf, nb);

    // Print the file descriptor number for DDD.txt
    printf("FD=%d\n", fd);

    // Clean up and close the file descriptors
    close(fd);
    close(fd1);

    return 0;
}

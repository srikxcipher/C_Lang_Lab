#include <stdio.h>
#include <unistd.h>  // for fork()
#include <sys/types.h> // for pid_t

pid_t add(pid_t a, pid_t b) {
    return a + b;
}

int main(void) {
    pid_t x = 10;
    printf("%d\n", x);  // First print
    x = add(fork(), fork());  // Call add() after two fork() calls
    printf("%d\n", x);  // Second print
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Please provide a positive integer.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {  // Child process
        int a = 0, b = 1, next;
        if (n >= 1) printf("%d ", a);
        if (n >= 2) printf("%d ", b);

        for (int i = 3; i <= n; i++) {
            next = a + b;
            printf("%d ", next);
            a = b;
            b = next;
        }
        printf("\n");
    } else if (pid > 0) {  // Parent process
        wait(NULL);  // Wait for the child process to complete
    } else {
        perror("fork failed");
        return 1;
    }

    return 0;
}

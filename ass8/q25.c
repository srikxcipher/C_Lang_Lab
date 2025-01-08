#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // First fork: Create the first child (PID=1235)
    pid = fork();
    if (pid == 0) {
        // In the first child (PID=1235)
        fprintf(stderr, "PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());
        return 0;
    } else if (pid > 0) {
        // Parent process continues here

        // Second fork: Create the second child (PID=1236)
        pid = fork();
        if (pid == 0) {
            // In the second child (PID=1236)
            fprintf(stderr, "PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());

            // Create child 21 from child 2 (PID=1237)
            pid = fork();
            if (pid == 0) {
                // In child 21 (PID=1237)
                fprintf(stderr, "PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());
                return 0;
            }

            // Create child 22 from child 2 (PID=1238)
            pid = fork();
            if (pid == 0) {
                // In child 22 (PID=1238)
                fprintf(stderr, "PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());

                // Create child 221 from child 22 (PID=1239)
                pid = fork();
                if (pid == 0) {
                    // In child 221 (PID=1239)
                    fprintf(stderr, "PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());

                    // Create child 2211 from child 221 (PID=1240)
                    pid = fork();
                    if (pid == 0) {
                        // In child 2211 (PID=1240)
                        fprintf(stderr, "PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());
                        return 0;
                    }
                }
            }
            return 0;
        }

        // Third fork: Create the third child (PID=1241)
        pid = fork();
        if (pid == 0) {
            // In the third child (PID=1241)
            fprintf(stderr, "PID=%ld PPID=%ld\n", (long)getpid(), (long)getppid());
            return 0;
        }

        // Wait for all child processes to finish
        wait(NULL);  // Wait for child 1 (PID 1235)
        wait(NULL);  // Wait for child 2 (PID 1236)
        wait(NULL);  // Wait for child 21 (PID 1237)
        wait(NULL);  // Wait for child 22 (PID 1238)
        wait(NULL);  // Wait for child 221 (PID 1239)
        wait(NULL);  // Wait for child 2211 (PID 1240)
        wait(NULL);  // Wait for child 3 (PID 1241)
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return -1;
    }

    return 0;
}

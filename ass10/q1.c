#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int shared_value = 5;  // Shared variable (not a pointer yet)
    int *shrd = &shared_value;  // Pointer to the shared variable

    pid_t pid1, pid2;

    // Create process P-1
    pid1 = fork();
    if (pid1 == 0) {
        // P-1 executes
        int x = *shrd;      // Dereference to read shared variable
        x = x + 1;         // Increment by 1
        sleep(1);          // Simulate some processing
        *shrd = x;          // Dereference to write back to shared variable
        printf("P-1 writes: %d\n", *shrd);
        return 0;
    }

    // Create process P-2
    pid2 = fork();
    if (pid2 == 0) {
        // P-2 executes
        int y = *shrd;      // Dereference to read shared variable
        y = y - 1;         // Decrement by 1
        sleep(1);          // Simulate some processing
        *shrd = y;          // Dereference to write back to shared variable
        printf("P-2 writes: %d\n", *shrd);
        return 0;
    }

    // Wait for both child processes to finish
    wait(NULL);
    wait(NULL);

    // Final value of shared variable
    printf("Final value of shared variable (shrd): %d\n", *shrd);
    
    return 0;
}

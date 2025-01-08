#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <sys/stat.h>

int main() {
    sem_t *sync;   // Declare the semaphore
    pid_t pid;

    // Create and initialize the semaphore `sync` with an initial value of 0
    sync = sem_open("/sync_semaphore", O_CREAT | O_EXCL, 0660, 0);
    if (sync == SEM_FAILED) {
        perror("sem_open failed");
        return 1;
    }

    pid = fork();  // Create a child process

    if (pid == 0) {  // Child process (Process 2)
        // Wait for the signal from Process 1
        sem_wait(sync);  // This will block until Process 1 signals

        // Execute statement b
        printf("Process 2: Executing statement b\n");

        // Cleanup semaphore and exit
        sem_close(sync);
        return 0;
    } else {  // Parent process (Process 1)
        // Execute statement a
        printf("Process 1: Executing statement a\n");

        // Signal the child process to execute statement b
        sem_post(sync);  // Allow Process 2 to execute by incrementing `sync`

        // Wait for the child process to finish
        wait(NULL);

        // Cleanup semaphore
        sem_close(sync);
        sem_unlink("/sync_semaphore");

        return 0;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
    // Create semaphores for synchronization
    sem_t *sem1 = sem_open("/sem1", O_CREAT, 0644, 0);
    sem_t *sem2 = sem_open("/sem2", O_CREAT, 0644, 1);
    sem_t *sem3 = sem_open("/sem3", O_CREAT, 0644, 0);
    sem_t *sem4 = sem_open("/sem4", O_CREAT, 0644, 0);
    sem_t *sem5 = sem_open("/sem5", O_CREAT, 0644, 0);



    pid_t pid;

    // Create child processes using fork() and each will print a message
    if ((pid = fork()) == 0) { // Child 1
        sem_wait(sem1);
        fprintf(stderr, "Coronavirus ");
        sem_post(sem4);  
        exit(0);
    } else if ((pid = fork()) == 0) { // Child 2
        sem_wait(sem2);
        fprintf(stderr, "\nWHO: ");
        sem_post(sem1);  
        exit(0);
    } else if ((pid = fork()) == 0) { // Child 3
        sem_wait(sem3);
        fprintf(stderr, "COVID-19 ");
        sem_post(sem5);  
        exit(0);
    } else if ((pid = fork()) == 0) { // Child 4
        sem_wait(sem4);
        fprintf(stderr, "disease ");
        sem_post(sem3);  
        exit(0);
    } else if ((pid = fork()) == 0) { // Child 5
        sem_wait(sem5);
        fprintf(stderr, "pandemic.\n");
        exit(0);
    }

    // Parent process: wait for all children
    sem_post(sem2); // Start the execution for the second child

    // Wait for all children to terminate
    for (int i = 0; i < 5; i++) {
        wait(NULL);  // Wait for child processes to terminate
    }

    // Clean up semaphores
    sem_close(sem1);
    sem_close(sem2);
    sem_close(sem3);
    sem_close(sem4);
    sem_close(sem5);
    sem_unlink("/sem1");
    sem_unlink("/sem2");
    sem_unlink("/sem3");
    sem_unlink("/sem4");
    sem_unlink("/sem5");

    return 0;
}

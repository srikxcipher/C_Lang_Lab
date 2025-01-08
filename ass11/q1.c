#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define BLKSIZE 8

int main()
{
    int id, *p, *p1, *p2, *p3;
    struct shmid_ds s;   // Declare the shared memory info structure
    key_t key;
    
    key = ftok("p.c", 20); // Generate a key
    printf("key=%#X\n", key);
    
    // Create a shared memory segment with size of int (4 bytes)
    id = shmget(key, sizeof(int), 0660 | IPC_CREAT);
    if (id == -1) {
        perror("shmget failed");
        return 1;
    }
    printf("Shm id=%d\n", id);

    // Attach the shared memory segment 4 times
    p = (int *)shmat(id, NULL, 0);
    p1 = (int *)shmat(id, NULL, 0);
    p2 = (int *)shmat(id, NULL, 0);
    p3 = (int *)shmat(id, NULL, 0);

    // Check and display the number of current attachments
    if (shmctl(id, IPC_STAT, &s) == -1) {
        perror("shmctl failed");
        return 1;
    }

    // Print the number of attachments
    printf("Number of current attachments: %ld\n", s.shm_nattch);

    // Infinite loop to keep the shared memory segment alive
    while (1);

    return 0;
}

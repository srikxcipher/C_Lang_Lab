#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {

    sem_t *sem1 = sem_open("/sem1", O_CREAT, 0644, 1); // Start Process 1 (XX)
    sem_t *sem2 = sem_open("/sem2", O_CREAT, 0644, 0); // Start Process 2 (Y)
    sem_t *sem3 = sem_open("/sem3", O_CREAT, 0644, 0); // Start Process 3 (ZZ)

    pid_t p1,p2;

    // Create child processes 
    p1 = fork();
    if(p1==0){
        p2 = fork();
        if(p2==0){
	    for(int i=1; i<=4; i++){
	        sem_wait(sem1);
                fprintf(stderr, "XX");
		sem_post(sem2);
            }
        }
        else{
            for(int i=1; i<=7; i++){
                sem_wait(sem2);
	        fprintf(stderr, "Y");
                if(i%2) sem_post(sem3);
		else sem_post(sem1);
            }
        }
   }
    else{
          for(int i=1; i<=4; i++){
               sem_wait(sem3);
               fprintf(stderr,"ZZ");
               sem_post(sem2);
 	  }
   }

    return 0;
}

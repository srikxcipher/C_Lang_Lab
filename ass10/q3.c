#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<semaphore.h>
int main()
{
  sem_t *S,*Q;
  int val;pid_t pid;
  S=sem_open("/sem_1",O_CREAT,0660,0);
  Q=sem_open("/sem_2",O_CREAT,0660,0);
  pid=fork();
  if(pid==0){
     sem_getvalue(S,&val);
     printf("Val in child=%d\n",val);
      for(;;){
        sem_wait(S);
        fprintf(stderr,"C");
       sleep(1);
       sem_post(Q);
    }
    }
    else{
    sem_getvalue(S,&val);
     printf("Val in parent=%d\n",val);
      for(;;){
        sem_wait(Q);
        fprintf(stderr,"P");
        sleep(1);
        sem_post(S);
    }
    }
   return 0;
 }

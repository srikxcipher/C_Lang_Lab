#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<semaphore.h>
int main()
{
  sem_t *s1,*s2;
  int val;pid_t pid;
  s1=sem_open("/xyz",O_CREAT,0660,1);
  s2=sem_open("/pqr",O_CREAT,0660,0);
  pid=fork();
  if(pid==0){
     sem_getvalue(s1,&val);
     printf("Val in child=%d\n",val);
      while(1){
        sem_wait(s1);
        fprintf(stderr,"C");
       sleep(1);
       sem_post(s2);
    }
    }
    else{
    sem_getvalue(s1,&val);
     printf("Val in parent=%d\n",val);
      while(1){
        sem_wait(s2);
        fprintf(stderr,"P");
        sleep(1);
        sem_post(s1);
    }
    }
   return 0;
 }

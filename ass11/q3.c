#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
  int id,*p;
   key_t key;
   key=ftok(".",45);
   id=shmget(key,sizeof(int), 0660|IPC_CREAT);
   pid_t pid=fork();
   if(pid==0){
        int *c;
       c=(int *)shmat(id, NULL, 0);
       *c=100;
       sleep(10);
       fprintf(stderr,"\nvalue=%d\n",*c);
   }
   else{
      //wait(NULL);
      sleep(4);
      p=(int *)shmat(id, NULL, 0);
       *p=100*2;
       //printf("value=%d\n",*p);
    }
    return 0;
    }
     
       
       

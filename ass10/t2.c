#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<semaphore.h>
int main(){
  sem_t *s1,*s2;
  int val;pid_t pid;
  s1=sem_open("/xy",O_CREAT,0660,0);
   s2=sem_open("/pq",O_CREAT,0660,1);
   while(1){
        sem_wait(s2);
        fprintf(stderr,"1 ");
        sleep(1);
        sem_post(s1);
    }
   return 0;
 }

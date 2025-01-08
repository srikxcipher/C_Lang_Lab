#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
  int id, *p;
  struct shmid_ds S;
key_t key;
key = ftok("p.c",500);
printf("Key=%#X\n",key);
id=shmget(key,sizeof(int),0660);
printf("shm id=%d\n",id);
p=(int *)shmat(id,NULL,0);
*p=600;
return 0;
}

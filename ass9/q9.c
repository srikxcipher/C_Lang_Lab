#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void) {
int fd[2],fs[2],fds[2];
pid_t pid;
pipe(fd);
pid=fork();
if(pid!=0){
pipe(fs);
pipe(fds);
}
else{
wait(NULL);
printf("Child waits\n");
}
while(1);
return 0;
}

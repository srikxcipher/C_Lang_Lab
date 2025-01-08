#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){

pid_t pid = fork();

char *arg[] = {"./mul",NULL};

if(pid==0){
	fprintf(stderr,"Child PID: %d\n", getpid());
	execvp("./mul",arg);
	perror("Exec error :");
	return 0;

} else {

	pid_t wr;
	int status;
	fprintf(stderr,"Parent PID: %d\n",getpid());
	wr = wait(&status);
	fprintf(stderr,"wr=%d status=%d \n",wr,WEXITSTATUS(status));
	return 0;
}
}


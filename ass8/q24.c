#include<stdio.h>
#include<unistd.h>

int main(void){
fprintf(stderr,"PID = %ld\n",(long)getpid());
while(1)
      sleep(1);
return 0;
}

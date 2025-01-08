#include <stdio.h>
#include <unistd.h> // for fork()
int main(){
pid_t p1,p2;
p2=0;
p1=fork();
if (p1 == 0)
p2 = fork();
if (p2 > 0)
fork();
printf("done\n");
while(1);
return 0;
}

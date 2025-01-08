#include <stdio.h>
#include <unistd.h> // for fork()

int main(){
if(fork()){
if(!fork()){
fork();
printf("S ");
}
else{
printf("T ");
}
}
else{
printf("D ");
}
printf("A ");
while(1);
return 0;
}

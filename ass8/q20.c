#include <stdio.h>
#include <unistd.h> // for fork()

int main(){int i;
for(i=0;i<12;i++){
if(i%3==0){
fork();
}
}
while(1);
return 0;
}

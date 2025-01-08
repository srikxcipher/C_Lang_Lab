#include <stdio.h>
#include <unistd.h> // for fork()

int x;
int a[2]={10,20};
x= 5 + a[fork() || fork()];
printf("%d ",x);
return 0;
}

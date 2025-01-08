#include <stdio.h>
#include <unistd.h> // for fork()
//#include <sys/wait.h>
int main(void) {
    int x[] = {10, 20, fork(), fork() + fork()};
    int len = sizeof(x) / sizeof(int); // Get the length of the array `x`
    
    for (int i = 0; i < len; i++)
        fprintf(stderr, " %d ", x[i]); // Print elements of the array to stderr
    
    printf("\n");
    sleep(2);
    return 0;
}

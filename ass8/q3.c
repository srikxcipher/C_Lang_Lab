//3. Run the following code on your machine and write the output. Suggest a way to avoid the mismatch
//of machine output w.r.t. dry run output.
#include<stdio.h>
#include<unistd.h>
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
return 0;
}

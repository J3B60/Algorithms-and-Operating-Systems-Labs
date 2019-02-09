#include <stdio.h>
void main(){
	fork();
	fork();
	printf("Process ID is: %d\n", getpid());
	printf("Parent Process ID is %d\n", getppid());
	sleep(2);
}

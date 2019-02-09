#include <stdio.h>
void main(){ //fork func returns value
	int ret = fork();/* Note ret = 0 if return to child process else return to parent with no zero, child PID (process ID)*/
	if (ret == 0){ /* this is child process */
		printf("The child process ID is %d\n", getpid());
		printf("The child's parent process ID is %d\n", getppid());
	} else{ /* this is the parent process */
		printf("The parent process ID is %d\n", getpid());
		printf("The parent's parent process ID is %d\n", getppid());
	}
	sleep(2);
}

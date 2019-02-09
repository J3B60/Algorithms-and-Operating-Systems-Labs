#include <stdlib.h>
#include <unistd.h>
void main(){
	int pid = fork();
	if (pid<0){ /*If fork <0 then error/fail*/
		printf("fork failed"); exit(1);
	} else if (pid == 0) {
		execlp("whoami", "ls",NULL);
		exit(0);
	} else {
		printf("\n Process id is -%d\n", getpid());
		wait(NULL);
		exit(0);
	}
}

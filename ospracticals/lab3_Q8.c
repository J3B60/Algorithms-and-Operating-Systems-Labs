#include <stdio.h>

void main(){
	int ret = fork();
	int count = 0;
	while (count < 10){
		if (ret == 0){
			printf("Child process: counter=%d\n", count);
		} else {
			printf("Parent process: counter=%d\n", count);
		}
		count++;
		sleep(1);
	}
}

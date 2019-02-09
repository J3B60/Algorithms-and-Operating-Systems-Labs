#include <stdio.h>

void main(){
	static int count = 0;
	int ret;
	while (count < 10){
		ret = fork();
		if (ret == 0){
			printf("Child process: counter=%d", count);
		} else {
			printf("Parent process: counter=%d", count);
		}
		sleep(1);
	}
}

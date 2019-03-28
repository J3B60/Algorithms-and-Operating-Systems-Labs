#include <stdio.h>

int count = 0;//Global counter

void main(){
	int ret = fork();
	while (count < 200){
		if (ret == 0){
			printf("The child process counter is %d\n", count);
		} else {
			printf("The parent process counter is %d\n", count);
		}
		count++;
		//sleep(1);
	}
}

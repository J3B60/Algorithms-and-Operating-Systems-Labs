#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

volatile sig_atomic_t got_usr1;

void sigusr1_handler(int sig){
	printf("Kirk3 using transporter\n");
	got_usr1 = 1;
};

struct my_msgbuf {
	long mtype;
	char mtext[200];
};

int main(void){
	struct sigaction sa;
	sa.sa_handler = sigusr1_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	struct my_msgbuf buf;
	int msqid;
	key_t key;
	
	int pid = getpid();
	
	printf("Kirk3's PID: %d\n", pid);
	
	if ((key = ftok("kirk.c", 'B')) == -1) {
		perror("ftok");
		exit(1);
	}
	
	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
		perror("msgget");
		exit(1);
	}
	
	printf("Enter lines of text, ^D to quit:\n");
	
	buf.mtype = 2; /* we don't really care in this case */
	
	while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
		int len = strlen(buf.mtext);
	
		/* ditch newline at end, if it exists */
		if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';

		if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
			perror("msgsnd");
	}
	
	if (msgctl(msqid, IPC_RMID, NULL) == -1) {
		perror("msgctl");
		exit(1);
	}
	
	return 0;
}

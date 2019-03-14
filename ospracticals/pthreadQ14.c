#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#define N 16 	/* define the total number of processes we want */

float total=0;	/* Set gloval variable */

int compute(int pid)	/* compute function just does something. */
{
	int i;
	float result=0;
	
	/* for a large number of times */
	for(i=0;i<2000000000;i++)
		result = sqrt(1000.0) * sqrt(1000.0);
	
	/* Print the result - should be no suprise */
	printf("Result of %d is %f\n", pid, result);
	
	/* to keep a running total in the global variable total */
	total = total + result;
	
	/* Print running total so far. */
	printf("Total of %d isread_crea %f\n", pid, total);
	
	return 0;
} //continue

int main()
{	pthread_t threads[N];
	pthread_attr_t attr;
	int rc;
	long t;
	void *status;
	//
	int cid[N], i, pid;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	printf("\n"); /* bit of whitespace */
	
	/* to loop and create the required number of processes */
	/* NOTE carefully how only the child process is left to run */
	for(i=0;i<N;i++)
	{ /* DO the pthread and catch it if it/one fails */
		if(rc=pthread_create(&threads[i], &attr, compute,pid)) exit(-1);
		/* a child? Yes, do our computation */
		else
		{ /* give message about the proc ID */
			pid = getpid();
			printf("Process ID for process %d is %d\n", i, pid);
			
			/* call the function to do some computation */
			//compute(pid);//DONTNEED???????
			
			/* After computation, quit. OR process creation will bom! */
			break;
		}
	}
	/* Pthread Joining */
	pthread_attr_destroy(&attr);
	for(t=0; t<N; t++){
		rc = pthread_join(threads[t], &status);
		//if(rc) {
		//	exit(-1);
		//}
		//printf()
	}
	pthread_exit(NULL);
}
//pthread_join();
//shift+H Report thread

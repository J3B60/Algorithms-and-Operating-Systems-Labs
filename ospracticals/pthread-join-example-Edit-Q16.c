#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3

float total = 0;

pthread_mutex_t mymutex;//MUTEX DEF

void *compute(void *t)
{
	int i;
	float result=0;
	//
	long tid;
	tid = (long)t;
	printf("Thread %ld starting...\n",tid);
	//
	/* for a large number of times */
	for(i=0;i<2000000000;i++)
		result = sqrt(1000.0) * sqrt(1000.0);
	
	/* Print the result - should be no suprise */
	printf("Result of %ld is %f\n", tid, result);
	
	pthread_mutex_lock (&mymutex);//MUTEX LOCK
	/* to keep a running total in the global variable total */
	total = total + result;
	pthread_mutex_unlock (&mymutex);//MUTEX UNLOCK

	/* Print running total so far. */
	printf("Total of %ld isread_crea %f\n", tid, total);
	
	pthread_exit((void*) t);
}

int main (int argc, char *argv[])
{
   pthread_t thread[N];
   pthread_attr_t attr;
   int rc;
   long t;
   void *status;

	pthread_mutex_init (&mymutex, NULL);//MUTEX INIT

   /* Initialize and set thread detached attribute */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for(t=0; t<N; t++) {
      printf("Main: creating thread %ld\n", t);
      rc = pthread_create(&thread[t], &attr, compute, (void *)t); 
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
         }
      }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for(t=0; t<N; t++) {
      rc = pthread_join(thread[t], &status);
      if (rc) {
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
         }
      printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
      }
 
printf("Main: program completed. Exiting.\n");
pthread_mutex_destroy(&mymutex);//END MUTEX
pthread_exit(NULL);
}


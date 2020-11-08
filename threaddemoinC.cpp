#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid) {
	
	/*This function prints the thread's identifier and then exits. */
	printf("Hello, world. Greetings from thread %d0\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	/*The main program creates 10 threads and then exits*/
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;
	
	for (i = 0; i < NUMBER_OF_THREADS; i++) {
		status = pthread_create(&threads[i], NULL, print_hello_world, (void*)i);
		printf("Main here. Creating threads %d0\n", i);
		//status = pthread_create(&threads[i], NULL, print_hello_world, (void*)i);
		
		if (status != 0) {
			printf("Oops. pthread_creat returned error code %d0, status\n");
			exit(-1);
		}
	}
	exit(NULL);
}

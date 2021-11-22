#include <stdio.h>
#include <pthread.h>

int x;

void *my_pthread_fn(void *arg)
{
	// Critical section
	// Insert Wait() here
	x++; // LD  R0, x
		 // INC R0
		 // ST 	x, RO
	// Insert Signal() here
	///
	
    return NULL;
}


int main()
{
	const int NUMTHREADS = 1024;
	pthread_attr_t myattr;
	x = 0;
	
    pthread_t mythread[NUMTHREADS];

	for(int i=0; i<NUMTHREADS; i++)
	{
		pthread_attr_init(&myattr);
		int err = pthread_create (&mythread[i], &myattr, my_pthread_fn, NULL); // ==> FORK
		pthread_attr_destroy(&myattr);
	}
	
    void *returnvalue;
	for(int i=0; i<NUMTHREADS; i++)
		pthread_join(mythread[i], &returnvalue); // <== JOIN
	
	printf("x is %d\n", x);
    
    return 0;
}
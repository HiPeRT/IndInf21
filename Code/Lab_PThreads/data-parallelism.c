#include <stdio.h>
#include <pthread.h>

#define SECONDS 1000000000.0
#include <time.h>
#include <sys/time.h>
unsigned long long gettime(void)
{
    struct timespec t;
    int r;

    r = clock_gettime(CLOCK_MONOTONIC, &t);
    if (r < 0) {
        fprintf(stderr,"Error to get time! (%i)\n", r);
        return -1;
    }

    return (unsigned long long) t.tv_sec * SECONDS + t.tv_nsec;
}


#define NUM_THREADS 4
#define N_ELEMENTS 20

int arr[N_ELEMENTS];

// void * is "like" Object for Java: can be used for generic type
void * pthreads_fn(void * args)
{
    int myid = (int) args; // This is my uniqe identifier, as assigned by programmer in main()

    // Here, we assume that N_ELEMENTS is a multiple of NUM_THREADS
    unsigned int chunk = N_ELEMENTS / NUM_THREADS;
    unsigned int istart = myid * chunk;
    unsigned int iend = istart + chunk;
    printf("Hello world, I am thread #%d. chunk is %u, istart is %u and iend is %u\n ", myid, chunk, istart, iend);

    for(int i=istart; i<iend; i++)
        arr[i] = i*2;

    return 0; // As per Unix philosophy, '0' means 'OK'
}

int main()
{
    pthread_t mythreads[NUM_THREADS];
    pthread_attr_t myattr;
    void *returnvalue;
    
    // Init arr
    for(int i=0; i<N_ELEMENTS; i++)
        arr[i] = 0;

    unsigned long long start_time = gettime();

    for(int i=0; i<NUM_THREADS; i++) // ==> FORK
    {
        pthread_attr_init(&myattr);
        int err = pthread_create (&mythreads[i], &myattr, pthreads_fn, (void *) i); // Pass 'i' as identifier for thread
        pthread_attr_destroy(&myattr);
    }

    // Now, the man (master) thread can do other useful stuff, here
    // while other (slave) threads execute in parallel
    
    for(int i=0; i<NUM_THREADS; i++) // <== JOIN
        pthread_join(mythreads[i], returnvalue); // Now, returnvalue contains the value returned by pthreads_fn
    
    unsigned long long end_time = gettime();

    //printf("start_time is %llu, end_time is %llu\n", start_time, end_time);
    printf("Computation took %f seconds (%llu ns)\n", (end_time - start_time) / SECONDS, end_time - start_time);

    // Quick check
    for(int i=0; i<N_ELEMENTS; i++)
        printf("arr[%d] is %d\n", i, arr[i]);

    return 0;
}
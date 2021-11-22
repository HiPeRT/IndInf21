#include <stdio.h>
#include <pthread.h>

int value;
void *foo(void * args)
{
    value = * (int *) args;
    printf("\t\t\t\t\t\t[foo()] Hello Parallel World! value is %d\n", value);

    value *= 2;

    //int res = pthread_exit(NULL);
    return (void*) &value;
}

int main()
{
    printf("Hello Sequential World!\n");

    /*
    int pthread_create ( pthread_t *ID,
                     pthread_attr_t *attr,
                     void *(*body)(void *),
                     void * arg
 			 );
    */

    //foo(NULL);

    pthread_t ID;
    int *retval = (int *) malloc(sizeof(int));
    int input_value = 11;
    pthread_attr_t myattr;
    int res = pthread_attr_init(&myattr);
    
    res = pthread_create(&ID, &myattr, foo, (void *) &input_value); // aka: create, fork, (spawn)
    printf("res is %d, ID is %d\n", res, (int) ID);

    res = pthread_join(ID, (void *) &retval); // join
    printf("res is %d, retval is %d\n", res, *retval);
    
    res = pthread_attr_destroy(&myattr);
    
    return 0;
}
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int count = 0;
pthread_rwlock_t count_rwlock;

void *reader1(void *data)
{
    int z;
    printf("Reader1: Entering critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Reader1: Inside critical section\n");
    z = count + 10;
    printf("Reader2: %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);
    printf("Reader1: Left critical section\n");
}

void *reader2(void *data)
{
    int x;
    printf("Reader2: Entering critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Reader2: Inside critical section\n");
    x = count + 20;
    printf("Reader2: %d\n",count);
    pthread_rwlock_unlock(&count_rwlock);
    printf("Reader2: Left critical section\n");
}

void *writer1(void *data)
{
    printf("Writer1: Entering critical section\n");
    pthread_rwlock_wrlock(&count_rwlock);
    printf("Writer1: Inside critical section\n");
    count++;
    pthread_rwlock_unlock(&count_rwlock);
    printf("Writer1: Left critical section\n");
}

int main(int argc,char const*argv[])
{
    pthread_t r1,r2,w1;
    pthread_rwlock_init(&count_rwlock,NULL);
    pthread_create(&r1,NULL,reader1,NULL);
    pthread_create(&r2,NULL,reader2,NULL);
    pthread_create(&w1,NULL,writer1,NULL);
    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(w1,NULL);
    pthread_rwlock_destroy(&count_rwlock);
    return 0;
}    
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int count=0;
sem_t meCount;

void *incThread(void *arg)
{
    while(1)
    {
      sem_wait(&meCount);
      count++;
      printf("Inc thread:%d\n",count);
      sem_post(&meCount);
    }
    
}
void *decThread(void *arg)
{
    while(1)
    {
       
       sem_wait(&meCount);
       count--;
       printf("Dec thread:%d\n",count);
       sem_post(&meCount);
    }
    
}

int main(int argc,char const*argv[])
{
    pthread_t inc,dec;
    sem_init(&meCount,0,1);
    pthread_create(&inc,NULL,incThread,NULL);
    pthread_create(&dec,NULL,decThread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    sem_destroy(&meCount);
    return 0;
}    
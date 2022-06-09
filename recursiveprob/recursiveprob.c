#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count=0;
pthread_mutex_t mutex_count;
pthread_mutexattr_t mutex_count_attr;

void *incThread(void *arg)
{
    while(1)
    {
      printf("Inc:Locking for 1st time\n");
      pthread_mutex_lock(&mutex_count);
      printf("Inc:Locking for 2nd time\n");
      pthread_mutex_lock(&mutex_count);
      printf("Inc:Changing count\n");
      count++;
      printf("Inc thread:%d\n",count);
      pthread_mutex_unlock(&mutex_count);
      printf("Inc:Unlocked 1st time\n");
      pthread_mutex_unlock(&mutex_count);
      printf("Inc:Unlocked 2nd time\n");
    }
    
}
void *decThread(void *arg)
{
    while(1)
    {
       printf("Dec:Locking\n");
       pthread_mutex_lock(&mutex_count);
       count--;
       printf("Dec thread:%d\n",count);
       pthread_mutex_unlock(&mutex_count);
       printf("Dec:Unlocking 1st time\n");
    }
    
}

int main(int argc,char const*argv[])
{
    pthread_t inc,dec;
    //Configure the mutex attributes
    pthread_mutexattr_init(&mutex_count_attr);
    pthread_mutexattr_settype(&mutex_count_attr,PTHREAD_MUTEX_RECURSIVE);
    //Initailize the mutex
    pthread_mutex_init(&mutex_count,&mutex_count_attr);
    pthread_create(&inc,NULL,incThread,NULL);
    pthread_create(&dec,NULL,decThread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    pthread_mutex_destroy(&mutex_count);
    return 0;
}    
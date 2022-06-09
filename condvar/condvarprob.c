#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <unistd.h>

int event = 0;
pthread_mutex_t event_mutex;

void *waiting_thread(void *data)
{
    printf("waiting thread:Grabbing the mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("waiting thread:Got the mutex\n");
    while(event!=1)
    {

    }
    printf("waiting thread:Event is 1,so I'm done\n");
    //Actual code 
    pthread_mutex_unlock(&event_mutex);
    printf("waiting thread:Released the mutex\n");
}

void *fire_event_thread(void *data)
{
    printf("fire event thread:Grabbing the mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("fire event thread:Got the mutex\n");
    event = 1;
    printf("fire event thread:Event is 1,so I'm done\n");
    pthread_mutex_unlock(&event_mutex);
    printf("fire event thread:Released the mutex\n");
}

int main(int argc,char const*argv[])
{
    pthread_t waiting_thread_id,fire_event_thread_id;
    pthread_mutex_init(&event_mutex,NULL);
    pthread_create(&waiting_thread_id,NULL,waiting_thread,NULL);
    pthread_create(&fire_event_thread_id,NULL,fire_event_thread,NULL);
    pthread_join(waiting_thread_id,NULL);
    pthread_join(fire_event_thread_id,NULL);
    pthread_mutex_destroy(&event_mutex);
    return 0;
}    
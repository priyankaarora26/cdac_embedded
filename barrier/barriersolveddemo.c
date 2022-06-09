#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t dev_init_barrier;

void *serial_thread(void *data)
{
    printf("Serial_thread:Init started\n");
    sleep(7);
    printf("Serial_thread:Init finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    // write some lines
    printf("Serial_thread:Main functionality\n");
}

void *ether_thread(void *data)
{
    printf("Ether_thread:Init started\n");
    sleep(10);
    printf("Ether_thread:Init finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("Serial_thread:Main functionality\n");
}

void *lcd_thread(void *data)
{
    printf("Lcd_thread:Init started\n");
    sleep(7);
    printf("Lcd_thread:Init finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("Serial_thread:Main functionality\n");
}

int main(int argc,char const*argv[])
{
    pthread_t serial_thread_id,ether_thread_id,lcd_thread_id;
    pthread_barrier_init(&dev_init_barrier,NULL,3);
    pthread_create(&serial_thread_id,NULL,serial_thread,NULL);
    pthread_create(&ether_thread_id,NULL,ether_thread,NULL);
    pthread_create(&lcd_thread_id,NULL,lcd_thread,NULL);
    pthread_join(serial_thread_id,NULL);
    pthread_join(ether_thread_id,NULL);
    pthread_join(lcd_thread_id,NULL);
    pthread_barrier_destroy(&dev_init_barrier);
    return 0;
}    

#include<stdio.h>
#include<pthread.h>
pthread_t tid;
void*display(void *data)
{

printf("This is thread \n");

}

int main()
{
    printf("before thread creation \n");
    pthread_create(&tid, NULL, display, NULL);
    sleep(1);
    printf("after thread creation \n");
    return 0;
}
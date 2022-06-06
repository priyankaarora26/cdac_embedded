#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int count = 0;
void *incThread (void *arg)
{
    while(1)
    {
        count++;
        printf("incThread : %d\n", count);
    }

}

void *decThread(void *arg)
 {
  while(1)
   {
     count--;
     printf("decThread : %d\n", count);
   }
 }
int main()
{
    pthread_t inc, dec;
    pthread_create (&inc, NULL, incThread, NULL);
    pthread_create (&inc, NULL, decThread, NULL);
    pthread_join(inc, NULL);
    pthread_join(dec, NULL);
    return 0;
}
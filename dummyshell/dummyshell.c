#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc,char const*argv[])
{
    pid_t id;
    id = fork();
    if(id == 0)
    {
        printf("I am child\n");
        execl("./forkdemo", "./forkdemo",NULL);
    }
    else 
    {
        printf("I am the Parent\n");
        wait(NULL);
    }
    return 0;
}    

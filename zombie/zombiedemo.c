#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    id = fork();
    if(id==0)
    {
        printf("Child Process with PID = %d PPID=%d\n",getpid(),getppid());  
        printf("Child completed\n");
    }
    else if(id>0)
    {
            printf("Parent Process with PID = %d  PPID=%d\n",getpid(),getppid());
            sleep(20);
            printf("Parent Completed");
    }
    else
    {
           perror("Fork Failed child not created\n");
    }  
    return 0;
}

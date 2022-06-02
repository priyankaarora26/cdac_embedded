#include<stdio.h>
#include <fcntl.h>             
#include <unistd.h>

#define MAX_BUFF_SIZ 5


int main(int argc, char const *argv[])
{
    unsigned char buff[MAX_BUFF_SIZ];
    pid_t id;
    int fd [2];
     //fd[0] is read
     //fd[1] is write
    
    pipe(fd);
    
    //two process

    id = fork();
    if (id == 0)
    {
        // child proces
        close (fd[1]);
        printf("child process\n");
        read(fd[0],buff ,sizeof (buff));
        printf("child: revived data: %s \n" , buff);
        

    }
    else
    {
      close (fd[0]);
      printf("parent process\n");
      write(fd[1],"DESD\n",5);
      printf("parents : wrote data");
    }
    

    return 0;
}

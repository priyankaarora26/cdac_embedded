#include<stdio.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int fd;
    fd=open("desd.txt",(O_CREAT|O_WRONLY));
    if(-1==fd)
    {
        perror("Error in opening the file! \n");
        exit(EXIT_FAILURE);
    }
    write(fd,"DESD\n",5);

    close(fd);
    exit(EXIT_SUCCESS);
    return 0;
}


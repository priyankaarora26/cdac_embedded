#include<stdio.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int fd=1;
    char *str=(char *)calloc(10,sizeof(char));
    fd=open("desd.txt",O_RDONLY);
    if(-1==fd)
    {
        perror("Error in opening the file! \n");
        exit(EXIT_FAILURE);
    }
    fd=read(fd,str,sizeof(str));

    if(fd==-1)
    {

        perror("Error in reading the file! \n");
        exit(EXIT_FAILURE);

    }

    printf("\n%s\n",str);

    close(fd);
    exit(EXIT_SUCCESS);
    return 0;
}


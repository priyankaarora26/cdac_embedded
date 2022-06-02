#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    unsigned char buff[1024];
    int fdr;
    fdr = open("desdfifo", O_RDONLY);
    read (fdr, buff , 5);
    printf ("read data: %s \n", buff);
    close(fdr);
    return 0;
}

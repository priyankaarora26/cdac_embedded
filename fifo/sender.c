#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    int fdw;
    fdw = open("desdfifo", O_WRONLY);
    write (fdw, "DESD\n", 5);
    close(fdw);
    return 0;
}

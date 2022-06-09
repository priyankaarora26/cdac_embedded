#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char const*argv[])
{
    printf("Before exec\n");
    execl("/bin/ls","ls",NULL);
    printf("After exec\n");
    return 0;
} 
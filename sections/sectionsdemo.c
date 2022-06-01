#include<stdio.h>
int add(int ,int);
int a;
int b=10;


int main(int argc, char const *argv[])
{
    int result=0;
    int *p =NULL;

    p=(int *)malloc(sizeof(int));
    int sum=add(10,20);
    printf("\nSum : %d",sum);

    return 0;
}

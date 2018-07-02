#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a=10;
    int* p=&a;
    printf("a=%d\n", a);
    printf("*p=%d\n", *p);

    *p=20;

    printf("a=%d\n", a);
    printf("*p=%d\n", *p);

    return 0;
}

#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a=2;
    int* p=&a;
    int** q=&p;

    printf("&a=0x%x, p=0x%x\n", &a, p);
    printf("&p=0x%x, q=0x%x\n", &p, q);

    printf("a=%d\n", **q);
    return 0;
}

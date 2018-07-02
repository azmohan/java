#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a[4][10];

    printf("a=0x%x, a+1=0x%x\n", a, a+1);
    printf("&a=0x%x, &a+1=0x%x\n", &a, &a+1);

    return 0;
}

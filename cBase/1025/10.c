#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a[10];

    printf("a=0x%x\n", a);
    printf("a+1=0x%x\n", a+1);
    printf("&a=0x%x\n", &a);
    printf("&a+1=0x%x\n", &a+1);

    return 0;
}

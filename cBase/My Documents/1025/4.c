#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a[10];
    int* p1=&a[0];
    int* p2=&a[9];

    printf("p2-p1=%d\n", p2-p1);
    printf("sizeof(a)=%d\n",sizeof(a));


    return 0;
}

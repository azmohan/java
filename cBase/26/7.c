#include    <stdio.h>

void func(int** p, int* b)
{
    *p=b;
}

int main(int argc, char *argv[])
{
    int a=10;
    int b=20;
    int* p=&a;
    func(&p, &b);
    printf("%d\n", *p);
    printf("a=%d,b=%d\n",a,b);

    return 0;
}

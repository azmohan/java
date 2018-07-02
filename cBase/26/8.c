#include    <stdio.h>

void func(int** p, int** q)
{
    int* tmp;
    tmp=*p;
    *p=*q;
    *q=tmp;
}
int main(int argc, char *argv[])
{
    int a=10;
    int b=20;

    int* p=&a;
    int* q=&b;
    printf("*p=%d, *q=%d\n",*p,*q);
    func(&p, &q);

    printf("*p=%d, *q=%d\n", *p, *q);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}

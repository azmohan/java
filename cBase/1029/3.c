#include    <stdio.h>

void setbit1(int* x, int n)
{
    *x=(*x) | (1<<n);
}

void setbit0(int* x, int n)
{
    *x=(*x)&(~(1<<n));
}

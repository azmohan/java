#include    <stdio.h>

void swap(int* a, int* b) 
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int main(int argc, char *argv[])
{
    int a=10;
    int b=20;
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    
    return 0;
}




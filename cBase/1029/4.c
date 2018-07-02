#include    <stdio.h>

void change(int* x)
{
    *x+=1;
}

int main(int argc, char *argv[])
{
    int n=10;
    change(&n);
    printf("n=%d\n", n);

    return 0;
}

#include    <stdio.h>

int main(int argc, char *argv[])
{
    int b=10;
    int c=20;
    int* const p=&b;
    
    //p=&c;
    *p=20;
    printf("b=%d\n", b);
    return 0;
}

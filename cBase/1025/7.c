#include    <stdio.h>

int main(int argc, char *argv[])
{
    int b=10;
    int c=20;
//    const int* p=&b;
    int* const p=&b;
   // p=&c;
    *p=30;
   // b=30;
    printf("*p=%d\n", *p);

    return 0;


}

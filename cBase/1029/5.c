#include    <stdio.h>

int*  change( int addr)
{
    int* point=NULL;
    point=&addr;
    return point;
}
int main(int argc, char *argv[])
{
    int a=10;
    int* p=NULL;
    int *pa = &a; 
    p= change(a);
   // p=&a;
    printf("*p=%d\n", *p);
    printf("p=%p,pa=%p\n",p,pa);

    return 0;
}

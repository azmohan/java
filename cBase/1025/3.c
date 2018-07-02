#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a=10;
    int *p=&a;
    printf("&a=0x%x\n",&a);
    printf("p=0x%x\n", p);
    printf("p+1=0x%x\n", p+1);
    printf("&p=0x%x\n",&p);
    printf("&p+1=0x%x\n",&p+1);
   // printf("&(p+1)=0x%x\n",&(p+1));

    return 0;
}

#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a[3][4]={0};
    printf("a=0x%x\n",a);
    printf("&a[0][0]=0x%x\n",&a[0][0]);
    printf("&a=0x%x\n",&a);
    printf("a+1=0x%x\n",a+1);
    printf("&a[0][0]+1=0x%x\n",&a[0][0]+1);
    printf("&a+1=0x%x\n",&a+1);
    printf("&a[0]=0x%x\n",&a[0]);
    printf("&a[0]+1=0x%x\n",&a[0]+1);
    return 0; 
}

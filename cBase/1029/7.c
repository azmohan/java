#include    <stdio.h>

void change( int (*p)[10], int len)
{
    for(int i=0; i<len; i++) {
        for(int j=0; j<10; j++) {
            p[i][j]=i*10+j;
        }
    }
}
int main(int argc, char *argv[])
{
    int a[3][10]={0};
    printf("a=%d\n",sizeof(a));
    printf("a[0]=%d\n",sizeof(a[0]));
    int len=sizeof(a)/sizeof(a[0]);

    printf("%d\n", len);

    change(a , len);

    for(int i=0; i<len; i++) {
        for(int j=0; j<10; j++) {
            printf("%-4d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

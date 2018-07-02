#include    <stdio.h>

void change(int* arr, int len)
{
    printf("%d\n",sizeof(arr));
    for(int i=0; i<len; i++) {
        arr[i]++;
    }
}
int main(int argc, char *argv[])
{
    int a[5]={0, 1, 2, 3, 4};
    printf("a=%d\n",sizeof(a));
    //printf("%d\n"，sizeof(a[0]));
   int len=sizeof(a)/sizeof(a[0]);

    change(a, len);
    for(int i=0; i<len; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}

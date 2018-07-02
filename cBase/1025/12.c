#include    <stdio.h>

int findmax(int* array, int len)
{
    printf("sizeof(arrary)=%lu\n", sizeof(array));
    int max=array[0];
    int pos=0;
    for(int i=1; i<len; i++) {
        if(array[i]>max)
        {
            max=array[i];
            pos=i;
        }
    }

    return pos;
}

int main(int argc, char *argv[])
{
    int a[5]={12, -34, 129, 100, -111};
    printf("sizeof(a)=%lu\n", sizeof(a));
    int len=sizeof(a)/sizeof(a[0]);
    int pos=findmax(a, len);

    printf("the max number is %d, and it's pos is %d\n", a[pos], pos);

    return 0;
}

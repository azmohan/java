#include    <stdio.h>

void sort(int* array, int len)
{
    int i;
    int j;
    int tmp;
    for(i=0; i<len-1; i++) {
        for(j=i+1; j<len; j++)
        {
            if(array[i]>array[j])
            {
                tmp=array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int a[10]={12,45,-12,-45,113,-789,1098, 44, 90909,  100};
    int len=sizeof(a)/sizeof(a[0]);

    int i;

    for(i=0; i<len; i++) {
        printf("%-5d", a[i]);
        if((i+1)%5==0)
        {
            printf("\n");
        }
    }
    sort(a, len);
    printf("\n");
    for(i=0; i<len; i++) {
        printf("%-5d", a[i]);
        if((i+1)%5==0)
        {
            printf("\n");
        }
    }
    return 0;

}

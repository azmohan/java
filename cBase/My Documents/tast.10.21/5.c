#include <stdio.h>

int main(void)
{
    int i,j;
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int b[3][4]={{12,11,10,9},{8,7,6,5},{4,3,2,1}};
    int c[3][4]={};
    printf("output array a:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("output array b:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
   // printf("output array b:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
           // printf("%d\t",b[i][j]);
      //  printf("\n");
            c[i][j]=a[i][j]+b[i][j];
    }

    
    printf("output array c:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }
}

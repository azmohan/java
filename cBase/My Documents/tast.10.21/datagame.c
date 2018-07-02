#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define uint unsigned int 

int main(void)
{
    int i,j,n;
    int a[4]={0}; /*数组赋初值*/
    goto addr;
   srand((uint)time(NULL));
    for(n=0;n<4;n++)
         a[n]=rand()%10;
    for(i=0;i<3;i++)
        for(j=i+1;j<4;j++)
            if((a[i]!=a[j])) /*四个数都不相同求反判断*/
            {
                  // printf("%d",rand()%10);  
               // printf("\n");

            }
    else
        addr;
        
    for(n=0;n<4;n++)
        printf("%d",a[n]);

}

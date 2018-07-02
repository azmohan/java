#include <stdio.h>

int main(void)
{
    int array[100];
    int j=50,k=0;
    for(int i=0;i<100;i++)
    {
        if(i<50)
        {
            
             array[i]=j++;
        }
        else
        
             array[i]=k++;
    }
    for(int i=0;i<100;i++)
    {
        printf("%d\t",array[i]);
        if((1+i)%10==0)
            printf("\n");
    }
    printf("\n");
}

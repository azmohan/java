#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i,a,b;
    /*for(i=0;i<10;i++)
        printf("%d\t",rand()%10);
    printf("\n");*/
    a=rand()%100;
    if(a/10==a%10)
    {
         printf("this is a wrong number:\n");
         printf("%d\n",a);}            
    else
       // printf("%d\n",a);
        printf("please input liang wei shu:\n");
        scanf("%d",&b);
        if(b<10&&b>=100)
            printf("input wrong!\n");
        else
            if(a==b)
                printf("1A2A,congratutations,you guess two datas.\n");
            if((a!=b)&&(a/10==b/10))
                printf("1A2B,congratutations,you guess the first data.\n");
            if((a!=b)&&(a%10==b%10))
                printf("1B2A,congratutations,you guess the second data.\n");
            if((a/10!=b/10)&&(a%10!=b%10))
                printf("1B2B,come on,you guess again.\n");
    printf("%d\n",a);            
    return 0;

}

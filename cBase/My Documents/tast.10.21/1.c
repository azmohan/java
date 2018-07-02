#include <stdio.h>

int main(void)
{
    int i,n=0;
    for(i=1;i<=100;i++)
    {
        if((!(i%7)||!(i%11))&&!(!(i%7)&&!(i%11)))
        {
                printf("%d\t",i);
                n++;
                if(!(n%5))
                    printf("\n");
        }
    }
    printf("\n");
    printf("%d\n",n);
    return 0;
}

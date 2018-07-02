#include <stdio.h>

int main(void)
{
    int i,j=0,n;
    float s=0;
    printf("input a number:\n");
    scanf("%d",&n);
    for(i=0 ;i<=n;i++)
    {
         i+=1;
         j+=i;
         s+=1.0/j;
    }
    printf("s=%.4f\n",s);
}

#include    <stdio.h>

long long fun(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(1==n || 0==n)
    {
        return 1;
    }
    else
    {
        return n*fun(n-1);
    }
}

int main()
{
   /* printf("sizeof(long int)=%d\n", sizeof(long int));
    printf("sizeof(int)=%d\n", sizeof(int));
    printf("sizeof(long long)=%d\n", sizeof(long long));
*/
    printf("10000!=%lld\n", fun(10000));
    return 0;
}

#include    <stdio.h>

long long fun(int n)
{
    if(0==n || 1==n)
    {
        return 1;
    }
    else
    {
        return fun(n-2)+fun(n-1);
    }
}

int main(int argc, char *argv[])
{
   // int n=atoi(argv[1]);

    printf("%lld\n", fun(5));

    return 0;
}

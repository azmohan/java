#include    <stdio.h>

unsigned int myabs(int n)
{
    if(n>=0)
    {
        return n;
    }
    else
    {
        return  -n;
    }
}
int main(int argc, char* argv[])
{
    int a=0x80000000;
    unsigned int b=myabs(a);
    printf("|%d|=%u\n", a, b);

    return 0;

}

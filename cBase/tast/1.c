#include    <stdio.h>
#define IN  1
#define OUT 0

int main(int argc, char *argv[])
{
    int c,nl,nw,nc,state;

    state = OUT;
    nl = nw = nc = 0;
    while(EOF != (c = getchar()))
    {
        nc ++;
        if('\n' == c)
            nl ++;
        if(' ' == c || '\n' == c || '\t' == c)
            state = IN;
        else if(OUT == state)
        {
            state = IN;
            nw ++;
        }
    }
    printf("nl = %d\n nw = %d\n nc = %d\n",nl,nw,nc);

    return 0;
}

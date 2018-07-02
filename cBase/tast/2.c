#include    <stdio.h>
#define IN  1
#define OUT 0

int main(int argc, char *argv[])
{
    int c , state;
    state = OUT;
    while(EOF != (c = getchar()))
    {
        if(' ' == c || '\n' == c || '\t' == c)
        {
            if(IN == state)
            {
                putchar('\n');
                state = OUT;
            }
        }
        else if(OUT == state)
        {
            state = IN;
            putchar(c);
        }
        else
            putchar(c);
    }


    return 0;
} 

#include    <stdio.h>
#define NONBLANK 'a'

/*replace string of blanks with a single blank*/
int main(int argc, char *argv[])
{
    int c,lastc;

    lastc=NONBLANK;   /*last char is not repeatable blank*/
    while((c=getchar())!=EOF)
    {
        if(' '!=c)
            putchar(c);
        else if(' '!=lastc)
            putchar(c);
        lastc=c;
    }
    return 0;
}

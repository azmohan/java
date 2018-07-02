#include    <stdio.h>

/*replace tabs and backspances with visible characters*/
int main(int argc, char *argv[])
{
    int c;

    while((c=getchar())!=EOF)
    {
        if('\t'==c)
            printf("\\t");
        else if('\b'==c)
            printf("\\b");
        else if('\\'==c)
            printf("\\\\");
        else
            putchar(c);
    }
    return 0;
}

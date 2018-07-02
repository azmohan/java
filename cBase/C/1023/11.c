#include    <stdio.h>

int main(int argc, char *argv[])
{
    char c='b';
    c=c-('a'-'A');
    printf("%c\n", c);

    return 0;
}

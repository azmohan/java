#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    char dest[100]="Hello ";
    char src[]="World";
//    char *pSrc = "World";
    char *pSrc = src;
    strcat(dest, src);
    puts(dest);
    src[0] = 'A';
    puts(src);
    pSrc[0] = 'b';
    puts(pSrc);

    return 0;
}

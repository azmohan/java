#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    char dest[100]="Hello ";
    char src[]="World";
    strcat(dest, src);
    puts(dest);

    return 0;
}

#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    char str1[]="hello";
    char str2[]="HELLO";

    int ret=strcmp(str1, str2);

    if(0==ret)
    {
        printf("%s=%s\n", str1, str2);
    }
    else if(ret>0)
    {
        printf("%s>%s\n", str1, str2);
    }
    else
    {
        printf("%s<%s\n", str1, str2);
    }

    return 0;
}

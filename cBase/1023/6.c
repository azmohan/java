#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    char str[]="Hello\0World\0";
    char * pStr = "Hello\0World\0";
    printf("sizeof(pStr)=%d\n",sizeof(pStr));
    printf("sizeof(str)=%d\n", sizeof(str));
    printf("strlen(str)=%d\n", strlen(str));

    return 0;
}

#include    <stdio.h>
#include    <string.h>
#define uint unsigned int 

uint mystrlen(const char* s);

int main(int argc, char *argv[])
{
    char ch[] = "I am a string!";
    char *ch1 = NULL;
    printf("strlen=%d\n",strlen(ch1));
    printf("mystrlen=%u\n",mystrlen(ch1));
    return 0;
}

uint mystrlen(const char* s)
{
    uint i=0;
    while(*s++ )
        i++;
    return i;
}

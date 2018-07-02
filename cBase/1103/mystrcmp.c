#include    <stdio.h>
#include    <string.h>

int mystrcmp(const char* s1,const char* s2);

int main(int argc, char *argv[])
{
    char* ch1 = "abcdefgef";
    char* ch2 = "abcdefgEfg";
    printf("mystrcmp=%d\n",mystrcmp(ch1,ch2));
    printf("strcmp=%d\n",strcmp(ch1,ch2));
    return 0;
}

int mystrcmp(const char* s1,const char* s2)
{
    for( ;*s1 == *s2;s1++,s2++)
        if(*s1 == '\0')
            return 0;
    return *s1 - *s2;
}

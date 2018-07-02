#include    <stdio.h>
#include    <string.h>

int mystrncmp(const char* s1,const char* s2,int n);

int main(int argc, char *argv[])
{
    char* ch1 = "I am a string!";
    char* ch2 = "To be number 1 !";

    return 0;
}

int mystrncmp(const char* s1,const char* s2,int n)
{
    char c1,c2;
    for( ; n>0 ; n--)
    {
        if(*s1++ == '\0'||*s2++ == '\0')
        {
            return *s++ - *s++;
        }

        if(*s1++ != *s2++)
            return *s1++ - *s2++;
    }

    return 0;

}

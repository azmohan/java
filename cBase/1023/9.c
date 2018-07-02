#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    char str1[]="Welcome to SAIF!";
    char str2[100]={0};
    puts(str2);
    strcpy(str2, str1);
    puts(str2);

    return 0;
}

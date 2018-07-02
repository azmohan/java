#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    char str1[100]="Hello \0Wrold!";
    //char str2[]="World!";
    //strcat(str1, str2);
    strcpy(str1+6, str1+7);
    puts(str1);

    return 0;
}

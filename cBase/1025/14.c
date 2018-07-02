#include    <stdio.h>

void replace(char* str, char old, char new)
{
    if(NULL==str)
    {
        return;
    }
    while(*str!='\0')
    {
        if(old==*str)
        {
            *str=new;
        }
        str++;
    }
}

int main(int argc, char *argv[])
{
    char str[]="Welcome to SAIF!";
    char str1[]="Hello World!";
   // printf("sizeof(str)=%d\n", sizeof(str));
    puts(str);
   // str=str1;
    //puts(str);
    replace(str, 'W', 'w');
    puts(str);

    return 0;
}

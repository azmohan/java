#include    <stdio.h>
#include    <string.h>
#define     SUCCESS 0
#define     ERROR  -1

int insertChar(char* str, int pos, char c)
{
    if(NULL==str)
    {
        return ERROR;
    }
    int len=strlen(str);

    if(pos>len)
    {
        return ERROR;
    }

    for(int i=len-1; i>=pos; i--) {
        str[i+1]=str[i];
    }
    str[pos]=c;
    str[len+1]='\0';

    return SUCCESS;

}

int main(int argc, char *argv[])
{
    char str[100]="Welcome to SAIF";
    int len=strlen(str);
    puts(str);
    int ret=insertChar(str, len, '!' );
    if(SUCCESS==ret)
    {
        puts(str);
    }
    else
    {
        printf("insertChar error!\n");

    }
    return 0;

    
}

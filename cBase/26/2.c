#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#define     SUCCESS 0
#define     ERROR -1

int delString(char* target, int pos, int len)
{
    if(NULL==target || pos<0 || len<0)
    {
        return ERROR;
    }
    int length=strlen(target);
    if(pos>=length)
    {
        return ERROR;
    }

    strcpy(target+pos, target+pos+len);
    return SUCCESS;

}

int findPos(char* target, char* del)
{
    if(NULL==target || NULL==del)
    {
        return ERROR;
    }

    int i=0;
    int ret;
    int len=strlen(del);
    char* tmp=(char*)malloc(sizeof(char)*(len+1));
    if(NULL==tmp)
    {
        return ERROR;
    }

    while(target[i]!='\0')
    {
        if(del[0]==target[i])
        {
            memset(tmp, 0, len+1);
            strncpy(tmp, &target[i], len);
            ret=strcmp(del, tmp);
            if(0==ret)
            {
                free(tmp);
                return i;
            }
        }
        i++;
    }

    return ERROR;
}

int main(int argc, char *argv[])
{
    char target[]="sdjksdjkjk";
    char* del="jk";
    int pos=0;
    int len=strlen(del);
    puts(target);
    while(pos!=ERROR)
    {
        pos=findPos(target, del);
        if(pos!=ERROR)
        {
            delString(target, pos, len);
        }

    }
    puts(target);

    return 0;
}

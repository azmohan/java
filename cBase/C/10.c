#include    <stdio.h>
#include    <string.h>

void sort_s(char* a,char* b,char* c)
{
    char *t;
    if(strcmp(a,b)>0)
    {
        if(strcmp(a,c)>0)
        {
            puts(a);
            if(strcmp(b,c)>0)
            {
                puts(b);
                puts(c);
            }
            else
            {
                puts(c);
                puts(b);
            }
        }
        else
        {
            puts(c);
            puts(a);
            puts(b);
        }
    }
    else
    {
        if(strcmp(b,c)>0)
        {
            puts(b);
            if(strcmp(a,c)>0)
            {
                puts(a);
                puts(c);
            }
            else
            {
                puts(c);
                puts(a);
            }
        }
        else
        {
            puts(c);
            puts(b);
            puts(a);
        }
    }
}

int main()
{
    char a[20],b[20],c[20];
    gets(a);
    gets(b);
    gets(c);
    sort_s(a,b,c);

    return 0;
}

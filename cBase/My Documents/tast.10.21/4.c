#include <stdio.h>

int main(void)
{
    char ch[]="abcdefghij";
    int i=0;
   // printf("%c\n",ch[10]);
    while(ch[i]!='\0')
    {
        printf("%c\t",ch[i]);
        i++;
    }
    printf("\n");

return 0;
}

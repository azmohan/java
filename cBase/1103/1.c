/*mystrncat函数*/
#include    <stdio.h>
#include    <string.h>

char* mystrncat(char* dest,const char* src,int n);

int main(int argc, char *argv[])
{
    char* ch1 = "I am a string!";
    char* ch2 = "To be number 1!";
    char* ch3 = NULL;
    ch3 = mystrncat(ch1,ch2);
    printf("%s\n",ch3);
    return 0;
}

char* mystrncat(char* dest,const char* src,int n)
{
    int i ;
    while(*dest+i)
        i++;

}

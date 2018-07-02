#include    <stdio.h>

void display(char ** str, int len)
{
    for(int i=0; i<len; i++) {
        printf("%s\n", str[i]);
    }
    
}

int main(int argc, char *argv[])
{
    char* str[]={"first", "second", "third"};
    display(str, 3);

    return 0;
}

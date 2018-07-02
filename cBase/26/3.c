#include    <stdio.h>
#include    <string.h>

char* array[]={"10", "20", "30", "40", "50", "60", "70"};
array[0]="10"; char* str="10";
*array[0]='1'; *(str+0)=str[0]='1';
array[1]="20";
int main(int argc, char *argv[])
{

    printf("sizeof(array)=%d\n", sizeof(array));
    return 0;
}

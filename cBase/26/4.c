#include    <stdio.h>

int main(int argc, char *argv[])
{
    int (*array)[10];
    printf("sizeof(array)=%d\n", sizeof(array));

    printf("array=0x%x\n", array);
    printf("array+1=0x%x\n", array+1);

    return 0;
}

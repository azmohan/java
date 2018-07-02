#include    <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char c=0xfc;
    unsigned short i=~c;

    printf("i=0x%x\n", i);

    return 0;
}

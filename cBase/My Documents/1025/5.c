#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a=0x12345678;
    void* p=&a;
    printf("*(char*)p=0x%x\n", *(char*)p);
    printf("*(short*)p=0x%x\n", *(short*)p);
    printf("*(int*)p=0x%x\n", *(int*)p);

    return 0;
}

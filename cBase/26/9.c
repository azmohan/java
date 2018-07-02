#include    <stdio.h>

void func1()
{
    printf("this is x86 platform!\n");

}

void func2()
{
    printf("this is ARM platform!\n");
}

int main(int argc, char *argv[])
{
    void (*pfunc)();

#ifdef ARM
    pfunc=func2;
    (**********pfunc)();
#else
    pfunc=func1;
    (**********pfunc)();
#endif
    return 0;
}

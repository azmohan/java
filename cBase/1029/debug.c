#include    <stdio.h>

#ifdef DB
    #define     DEBUG(format, ...)  printf(format, ##__VA_ARGS__)
#else
    #define     DEBUG(format, ...)  do{}while(0)
#endif

int main(int argc, char *argv[])
{
    DEBUG("info\n");
    return 0;
}

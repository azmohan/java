#include    <stdio.h>
#include    <unistd.h>

int main(int argc, char *argv[])
{
    printf("%s", "Hello World!");
    fflush(stdout);
    sleep(10);

    return 0;
}

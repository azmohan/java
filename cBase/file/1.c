#include    <stdio.h>

struct data
{
    int x;
    int y;
};
int main(int argc, char *argv[])
{
    struct data d;
    d.x=100;
    d.y=100;

    FILE* file=fopen("data1", "w+");

    int ret=fwrite(&d, sizeof(struct data), 1, file);

    fclose(file);
    return 0;
}

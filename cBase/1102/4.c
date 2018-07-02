#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    FILE* file=fopen("3.txt", "w+");
    for(int i=0; i<10000022; i++)
    {
        fwrite("H", 1, 1, file);
    }
    fclose(file);

    return 0;
}

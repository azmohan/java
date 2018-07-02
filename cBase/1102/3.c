#include    <stdio.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    FILE* file=fopen("2.txt", "w+");
    char str[]="Hello World";
    fwrite(str, 1, strlen(str), file);
    fseek(file, 10000000, SEEK_END);
    fwrite(str, 1, strlen(str), file);
    fclose(file);

    return 0;
}

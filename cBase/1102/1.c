#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    FILE* file=fopen("1.txt", "w+");
    if(NULL==file)
    {
        perror("fopen error:");
        exit(-1);
    }

    char str[]="Welcome to SAIF!";
    fwrite(str, sizeof(char), strlen(str), file);

    fclose(file);
    return 0;
}

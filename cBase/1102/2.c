#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
int main(int argc, char *argv[])
{
    FILE* file=fopen("1.txt", "a+");
    if(NULL==file)
    {
        perror("fopen error:");
        exit(-1);
    }

    char str[]="Hello World!";
    char str1[100]={0};
    fread(str1, sizeof(char), 7, file);
    printf("%s\n", str1);
    fwrite(str, sizeof(char), strlen(str), file);
   // memset(str1, 0, 100);
    int ret=fread(str1, 1, 8, file);
    printf("%d\n", ret);
    printf("%s\n", str1);
    fclose(file);
    return 0;
}

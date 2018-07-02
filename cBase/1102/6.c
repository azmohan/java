#include    <stdio.h>
#include    <stdlib.h>
int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        perror("argments error!");
        exit(-1);
    }
    FILE* srcFile=fopen(argv[1], "r");
    if(NULL==srcFile)
    {
        perror("srcFile is NULL:");
        exit(-1);
    }
    FILE* desFile=fopen(argv[2], "w+");
    if(NULL==desFile)
    {
        perror("desFile is NULL:");
        exit(-1);
    }
    int ret=0;

    char buf[4096];
    ret=fread(buf, 1, 4096, srcFile);
    while(ret!=0)
    {
       if(ret!= fwrite(buf, 1, ret, desFile))
       {
           perror("fwrite error:");
           exit(-1);
       }
       ret=fread(buf, 1, 4096, srcFile);
    }

    fclose(srcFile);
    fclose(desFile);

    return 0;
}

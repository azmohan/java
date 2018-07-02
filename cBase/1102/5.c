#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>

int main(int argc, char *argv[])
{
    if(3 != argc)
    {
        perror("parameter error");
        exit(-1);
    }

    FILE* srcFile = fopen(argv[1],"r");
    if(NULL == srcFile)
    {
        perror("srcFile error");
        exit(-1);
    }

    FILE* destFile = fopen(argv[2],"w+");
    if(NULL == destFile)
    {
        perror("destFile error");
        exit(-1);
    }

    int ret=0;
    char buf[4096]={0};

    ret = fread(buf,sizeof(buf[0]),sizeof(buf),srcFile);
    while(0 != ret)
    {
        if(ret != fwrite(buf,sizeof(buf[0]),ret,destFile))
        {
            perror("fwrite error");
            exit(-1);
        }
        ret = fread(buf,sizeof(buf[0]),sizeof(buf),srcFile);
    }
    fclose(srcFile);
    fclose(destFile);

    return 0;
}

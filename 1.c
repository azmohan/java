#include    <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    for(i = 0;i < argc;i++) {
        printf("main args,i=%d,args=%s\n",i,argv[i]);
    }
}
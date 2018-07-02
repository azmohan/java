#include    <stdio.h>
#include    <string.h>

int main(int argc, char *argv[])
{
    char word[20]={0};
    printf("word=0x%x\n",word);
    printf("word+1=0x%x\n",word+1);
    printf("&word=0x%x\n",&word);
    printf("&word+1=0x%x\n",&word+1);
   // scanf("%s",&word);
   // puts(word);
    return 0;
}

#include    <stdio.h>
#include    <string.h>
void insert(char* array,int index,char new); 

int main(int argc, char *argv[])
{
    char array[80]={0};
    int index=0;
    char new=0;
    printf("input a string:\n");
    gets(array);
    printf("strlen=%d\n",strlen(array));
    printf("input a index:\n");
    scanf("%d",&index);
    getchar();
    if(index>strlen(array))
    {
        printf("index is beyond strlen:\n");
        return 0;
    }
    printf("input a new char:\n");
    new=getchar();
    insert(array,index,new);
    puts(array);

    return 0;
}

void insert(char* array,int index,char new)
{
    int i=0,j=0;
    char str[80]={0};
    while('\0'==array[i])
    {
        if(index==i)
        {
            str[0]=new;
           // strcpy(str+1,array+i);
            while(array[i+j]=='\0')
            {
                str[j+1]=array[i+j];
                j++;
            }
            str[j+1]='\0';

            break;
        }
        i++;
    }
    strcpy(array+(i-1),str);
    printf("str=%s\n",str);


}

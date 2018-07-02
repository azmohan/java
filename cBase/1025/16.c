#include<stdio.h>
#include<string.h>

int main(void) {
    char str[] = "We change lives";
    char test[1]  = {'0'};
    strcpy(test,str);
    puts(test);
    return 0;
}

#include <stdio.h>

int main(void) {
    int x = 12;
    x = x-=x += x * x;
    printf("%d\n",x);
    return 0;
}

#include    <stdio.h>
unsigned int myabs(int a);
/*main begin*/
int main(int argc, char *argv[])
{
    int a;
    printf("inpunt a:\n");
    scanf("%d",&a);
    printf("|a| = %u\n",myabs(a));
    return 0;
} /*main over*/
/*myabs |a| */
unsigned int myabs(int a)
{
    if(a>=0)
        return a;
    else
        return -a;
}

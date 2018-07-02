#include<stdio.h>
#include"mat.h"
int main(void)
{
	float x,y;
	int flag=0;
	printf("please input x,y,flag:\n");
	scanf("%f%f%d",&x,&y,&flag);
	if(flag==0)
	printf("x+y=%.2f\n",add(x,y));
	else if(flag==1)
		printf("x-y=%.2f\n",sub(x,y));
#ifdef DEBUG
	else if(flag==2)
		printf("x*y=%0.2f\n",mul(x,y));
#endif
	else
		printf("x/y=%.2f\n",div(x,y));
	return 0;
}

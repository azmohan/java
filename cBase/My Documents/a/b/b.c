#include <stdio.h>

int main(void)

{
	int k;
	for(k=0;k<3;k++)
		add();
	return 0;
}
add()
{
	static int x=0;
	x++;
	printf("x=%d\n",x);	
}


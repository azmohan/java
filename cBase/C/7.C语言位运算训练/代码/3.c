//练习3、取一个无符号整数a从右边开始的4~7位
#include <stdio.h>

int main()
{
	unsigned int a=0xf0;
	unsigned int b;

	b=a>>4;
	b&=0xf;

	printf("%d\n", b);

	return 0;
}
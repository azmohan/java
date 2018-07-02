//练习2、从键盘输入一个无符号整数，打印出它的二进制表示位序列，每四位之间用空格分开。

#include <stdio.h>

//实现一个无符号数的二进制显示
void fun( unsigned int x)
{
	int i;
	char num[32];//保存32 位的数字	
	for (i=0; i<32; i++)
	{
		//加48是为了修正数字1和字符‘1’之间的差值
		num[32-1-i]=(x&1)+48;
		x=x>>1;
	}
	
	for (i=0; i<32; i++)
	{
		if (i>0&&i%4==0)
		{
			printf(" ");
		}
		printf("%c", num[i]);
	}
	printf("\n");
}
int main()
{
	unsigned int m;
	printf("Please input an unsigned integer:");
	scanf("%d",&m);

	fun(m);

	return 0;
}
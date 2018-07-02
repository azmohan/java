/*
1、练习：创建一个长度为100的整形数组，分别给元素赋值为0,1,2,3… …98,99

*/

#include <stdio.h>

int main(void)
{
	//数组a的最后一个元素为a[99]，不存在a[100]这个元素
	int a[100];
	int i;

	for (i=0; i<100; i++)
	{
		a[i]=i;
	}

	return 0;
}
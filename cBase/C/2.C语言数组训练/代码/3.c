/*
3、练习：创建两个长度为100的整形数组 a 和 b, 给 a 赋上初值，
然后把 a 里面每个元素的值复制到 b 里。

*/

#include <stdio.h>

int main(void)
{
	//数组a的最后一个元素为a[99]，不存在a[100]这个元素
	int a[100];
	int b[100];
	int i;

	for (i=0; i<=99; i++)
	{
		a[i]=i;
		
	}
	for (i=0; i<=99; i++)
	{
		b[i]=a[i];
	}

	return 0;
}
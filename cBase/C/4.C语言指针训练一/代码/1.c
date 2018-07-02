//编写函数 findmax, 从一个整形数组中找出来最大的一个数并返回数组下标. 
//函数原型如下：int findmax(int *array, int length)

#include <stdio.h>

int findmax(int* array, int length)
{
	int i;
	int j=0;
	int max=array[j];
	for (i=1; i<length; i++)
	{
		if (array[i]>max)
		{
			max=array[i];
			j=i;
		}
	}
	return j;
}

int main()
{
	int a[5]={5,2,100,4,5};
	int i=findmax( a, sizeof(a)/sizeof(a[0]) );
	printf("max=%d\n", a[i]);

	return 0;
}
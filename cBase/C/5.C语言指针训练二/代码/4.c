//请编一个函数fun(int *a,int n,int *odd,int *even)，
//函数的功能是分别求出数组中所有奇数之和以及所有偶数之和。
//形参n给了数组中数据的个数
//利用指针odd返回奇数之和，利用指针even返回偶数之和。

#include <stdio.h>
#include <conio.h>
#define N 20
/*注：该题的算法是：用for()循环一步一步地找元素，用if(!a[i]%2)来判断是否是奇
数，%运算是求余运算，当对2求余为1时表示原数为奇数，否则为偶数。*/
fun(int *a,int n,int *odd,int *even)
{ 
	int i; 
	*even=0;
	*odd=0;
	for(i=0;i<n;i++)
	{
		if(!(a[i]%2))
		{
			*even+=a[i];
		}
		else
		{
			*odd+=a[i];
		}

	}

}

int main()
{ 
	int a[N]={1,9,2,3,11,6},i,n=6,odd,even;
	
	printf("The original data is:\n");
	for(i=0;i<n;i++) 
	{
		printf("%5d",*(a+i));
	}
	printf("\n\n");
	fun(a,n,&odd,&even);
	printf("The sum of odd numbers:%d\n",odd);
	printf("The sum of even number:%d\n",even);

	return 0;
}

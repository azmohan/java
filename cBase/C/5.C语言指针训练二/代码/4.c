//���һ������fun(int *a,int n,int *odd,int *even)��
//�����Ĺ����Ƿֱ������������������֮���Լ�����ż��֮�͡�
//�β�n�������������ݵĸ���
//����ָ��odd��������֮�ͣ�����ָ��even����ż��֮�͡�

#include <stdio.h>
#include <conio.h>
#define N 20
/*ע��������㷨�ǣ���for()ѭ��һ��һ������Ԫ�أ���if(!a[i]%2)���ж��Ƿ�����
����%�������������㣬����2����Ϊ1ʱ��ʾԭ��Ϊ����������Ϊż����*/
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

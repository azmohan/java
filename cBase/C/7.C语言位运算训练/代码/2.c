//��ϰ2���Ӽ�������һ���޷�����������ӡ�����Ķ����Ʊ�ʾλ���У�ÿ��λ֮���ÿո�ֿ���

#include <stdio.h>

//ʵ��һ���޷������Ķ�������ʾ
void fun( unsigned int x)
{
	int i;
	char num[32];//����32 λ������	
	for (i=0; i<32; i++)
	{
		//��48��Ϊ����������1���ַ���1��֮��Ĳ�ֵ
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
//��ϰ3��ȡһ���޷�������a���ұ߿�ʼ��4~7λ
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
//��д��������
//void setbit1(int* x, int n); //��*x�ĵ�nλ��1
//void setbit0(int* x, int n);//��*x�ĵ�nΪ��0

#include <stdio.h>

void setbit1(int* x, int n)
{
	(*x)|=1<<n;
}

void setbit0(int* x, int n)
{
	(*x)&=~(1<<n);
}

int main()
{
	unsigned int m=0;
	unsigned int n=0xffffffff;

	setbit1(&m, 4);
	setbit0(&n, 4);
	printf("0x%x\n", m);
	printf("0x%x\n", n);

	return 0;
}
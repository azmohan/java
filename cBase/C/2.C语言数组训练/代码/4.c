/*
4����ϰ������һ������Ϊ10���ַ������飬��ʼ��Ϊabcdefghij ���ӡ������Ԫ��;
Ȼ��� a �����Ԫ����β���ù���������ӡ��

*/
#include <stdio.h>

int main(void)
{
	int i;
	char tmp;
	char a[10]={'a','b','c','d','e','f','g','h','i','j'};
	//˼���ܲ�������д��char a[10]="abcdefghij"
	
	for (i=0; i<10; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");
	//˼���ܲ���ֱ����printf("%s\n", a);

	for (i=0; i<10/2; i++)
	{
		tmp=a[i];
		a[i]=a[9-i];
		a[9-i]=tmp;
	}

	for (i=0; i<10; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");

	return 0;

	
}
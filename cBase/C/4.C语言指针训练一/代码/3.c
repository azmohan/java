//��д���� replace, ��һ���ַ������������ָ���ַ���������Ӧ���ַ������
//����ԭ�����£�
//void replace(char *array, char old, char new, int length)

#include <stdio.h>

void replace(char *arrray, char old, char new, int length)
{
	int i;
	for (i=0; i<length; i++)
	{
		if (arrray[i]==old)
		{
			arrray[i]=new;
		}
			
	}
}

int main()
{
	char str[]="Welcome to SAIF!";
	puts(str);
	replace(str, 't', 'T', sizeof(str)/sizeof(str[0]));
	puts(str);

	return 0;
}

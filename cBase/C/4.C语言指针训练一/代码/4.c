//��д���� insert, ��һ���ַ�����ָ��λ�ò���һ���ַ���������ַ���������ƶ���
//����ԭ�����£�(�����ǿռ䲻������)
//void insert(char *array, int index, char new)

#include <stdio.h>
#include <string.h>
#define N 128

//��ʵ���length�Ƕ����
void insert(char *array, int index, char new)
{
	int i;
	int length=strlen(array);
	for (i=length-1; i>=index; i--)
	{
		array[i+1]=array[i];
	}
	array[length+1]='\0';
	array[index]=new;
}

int main()
{
	char str[N]="Welcome o SAIF!";
	puts(str);	
	insert(str, 8, 't');
	puts(str);

	return 0;

}
//Ҫ�����������ַ��������Ӵ�С���

#include <stdio.h>
#include <string.h>
#define N 3
void sort(char (*s)[100])
{
	int i;
	int j;
	char tmp[100];
	for (i=0; i<N-1; i++)
	{
		for (j=i; j<N; j++)
		{
			if (strcmp(s+i, s+j)<0)
			{
				strcpy(tmp,s+i);
				strcpy(s+i, s+j);
				strcpy(s+j, tmp);
			}
		}
	}
}

void showstr(char (*s)[100])
{
	int i;
	for (i=0; i<N; i++)
	{
		puts(s+i);
	}
}

int main()
{
	char str[N][100]={"dddeeefff", "aaabbbccc", "ggghhhiii"};
	printf("����ǰ��\n");
	showstr(str);
	printf("�����\n");
	sort(str);
	showstr(str);

	return 0;

}
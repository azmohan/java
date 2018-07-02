//编写函数 replace, 在一个字符数组里面查找指定字符，并用相应的字符替代。
//函数原型如下：
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

//实现自己的mystrcpy函数，要求和strcpy函数一样。
#include <stdio.h>

char* mystrcpy(char *dest, char *src)
{
	int i=0;
	if (NULL==dest || NULL==src)
	{
		return NULL;
	}

	while (src[i]!='\0')
	{
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';
	return dest;
}

int main()
{
	char* str1="Welcome to SAIF!";
	char str2[128];
	mystrcpy(str2, str1);
	puts(str2);

	return 0;

}

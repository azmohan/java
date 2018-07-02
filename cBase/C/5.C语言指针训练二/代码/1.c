//实现自己的mystrlen函数，要求和strlen函数一样。
#include <stdio.h>

int mystrlen(char *s)
{
	int cnt=0;
	if (NULL==s)
	{
		return 0;
	}
	while (s[cnt]!='\0')
	{
		cnt++;
	}

	return cnt;
}

int main()
{
	char* str="Hello";

	printf("%d\n", mystrlen(str));
	return 0;
}
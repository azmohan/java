/************************************************************************/
/* 编一个函数fun(char *s),函数的功能是把字符串中的内容逆置。			 */
/************************************************************************/

#include <stdio.h>
#include <string.h>

#define N 128

void fun(char* s)
{
	int i=0;
	char tmp;
	int len=strlen(s);

	for (i=0; i<len/2; i++)
	{
		tmp=s[i];
		s[i]=s[len-1-i];
		s[len-1-i]=tmp;
	}
}

int main(void)
{
	char str[N]="123456789";
	fun(str);
	puts(str);

	return 0;
}
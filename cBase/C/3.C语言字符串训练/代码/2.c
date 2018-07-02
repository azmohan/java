//编写函数fun，函数的功能是：从字符串中删除指定的字符。               
//同一字母的大、小写按不同字符处理。                                    
//若程序执行时，字符串为：turbo c and Borland c++，要删除的字符为：n，  
//则输出后变为：turbo c ad borlad c++。                                 
//如果输入的字符串不存在，则字符串照原样输出。  

#include <stdio.h>
#include <string.h>
int fun(char* str, char c)
{
	int i;
	int len;
	if (str==NULL)
	{
		return -1;
	}

	len=strlen(str);
	

	for ( i=0; i<len; i++)
	{
		if (c==str[i])
		{
			strcpy(str+i, str+i+1);
		}
	}

	return 0;
}

int main(void)
{
	char str[128]="turbo c and Borland c++";
	fun(str, 'n');
	puts(str);

	return 0;

}
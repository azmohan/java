//��д����fun�������Ĺ����ǣ����ַ�����ɾ��ָ�����ַ���               
//ͬһ��ĸ�Ĵ�Сд����ͬ�ַ�����                                    
//������ִ��ʱ���ַ���Ϊ��turbo c and Borland c++��Ҫɾ�����ַ�Ϊ��n��  
//��������Ϊ��turbo c ad borlad c++��                                 
//���������ַ��������ڣ����ַ�����ԭ�������  

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
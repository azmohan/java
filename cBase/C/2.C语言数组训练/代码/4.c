/*
4、练习：创建一个长度为10的字符型数组，初始化为abcdefghij 后打印出各个元素;
然后把 a 里面的元素首尾到置过来，并打印。

*/
#include <stdio.h>

int main(void)
{
	int i;
	char tmp;
	char a[10]={'a','b','c','d','e','f','g','h','i','j'};
	//思考能不能这样写：char a[10]="abcdefghij"
	
	for (i=0; i<10; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");
	//思考能不能直接用printf("%s\n", a);

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
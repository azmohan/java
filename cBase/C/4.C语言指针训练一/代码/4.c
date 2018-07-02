//编写函数 insert, 向一个字符数组指定位置插入一个字符，后面的字符依次向后移动。
//函数原型如下：(不考虑空间不足的情况)
//void insert(char *array, int index, char new)

#include <stdio.h>
#include <string.h>
#define N 128

//其实这个length是多余的
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
//��Ҫʹ��ȫ�ֱ�������дһ����������������ĺ�����
//ԭ�����£�void sort(int *array, int length)

#include <stdio.h>

void sort(int *array, int length)
{
	int i;
	int j;
	int tmp;

	for ( i=0; i<length-1; i++)
	{
		for (j=i+1; j<length; j++)
		{
			if (array[i]>array[j])
			{
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
	}
}

void showarray(int* array, int length)
{
	int i;
	for (i=0; i<length; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

}

int main()
{
	int a[10]={21,342,-234,45,56,66,-12,34,34,10};
	int len=sizeof(a)/sizeof(a[0]);
	printf("����ǰ��\n");
	showarray(a, len);
	printf("�����\n");
	sort(a, len);
	showarray(a, len);

	return;

	
}
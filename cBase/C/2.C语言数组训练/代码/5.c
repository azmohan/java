/*
5������10��ѧ���ĳɼ��ֱ�Ϊ89��90��84��78��84��67��88��92��79��73��
��������� stu�У�������ǵ�ƽ���ɼ�aver(������λС��)�͵���ƽ���ɼ���������
*/
#include <stdio.h>

int main(void)
{
	int i;
	//��ȻҲ���԰�stu����д��double����
	int stu[10]={89, 90, 84, 78, 84, 67, 88, 92, 79, 73};
	double aver=0;
	int cnt=0;

	for (i=0; i<10; i++)
	{
		aver+=stu[i];
	}
	aver/=10;

	for (i=0; i<10; i++)
	{
		if (stu[i]<aver)
		{
			cnt++;
		}
	}

	printf("aver=%f, cnt=%d\n", aver, cnt);
	
	return 0;

	
}
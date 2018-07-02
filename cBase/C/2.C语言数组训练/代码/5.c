/*
5、设有10个学生的成绩分别为89、90、84、78、84、67、88、92、79、73，
存放在数组 stu中，输出它们的平均成绩aver(保留两位小数)和低于平均成绩的人数。
*/
#include <stdio.h>

int main(void)
{
	int i;
	//当然也可以把stu数组写成double类型
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
/************************************************************************/
/* ��������Ϸ                                                           */
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num[4]; //ȫ�ֱ����������������ɵ�����

int database[10];

void initDatabase(void)
{
	int i;
	for (i=0; i<10; i++)
	{
		database[i]=i;
	}
}

void creatNum(void)
{
	int cnt=0;
	int pos;
	initDatabase();
	srand((unsigned)time(NULL));
	
	while( cnt<4 )
	{
		pos=rand()%10;
		if ( database[pos]!=-1 )
		{
			num[cnt]=database[pos];
			database[pos]=-1;
			cnt++;
		}
	}
}



int main(void)
{
	int right=0;//λ����ȷ
	int wrong=0;//λ�ò���ȷ�����ֲ¶�
	int userdata[4];//�����û����������
	int i;
	int j;
	int guesscnt=0;//�²�Ĵ���
	creatNum();

	while(guesscnt<10)
	{
		printf("������4��0-9֮�������\n");
		right=0;
		wrong=0;
		for (i=0; i<4; i++)
		{
			scanf("%d", &userdata[i]);
		}

		for (i=0; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				if (userdata[i]==num[j])
				{
					if (i==j)
					{
						right++;
					}
					else
					{
						wrong++;
					}
					
				}
			}
		}
		if (right==4)
		{
			printf("you guess right!\n");
			break;
		}
		else
		{
			printf("%dA%dB\n", right, wrong);
		}
		
		guesscnt++;
	}
	
	if (guesscnt==10)
	{
		printf("��Ǹ����²�Ĵ����Ѿ�����10���ˣ�\n");
	}

	return 0;


}
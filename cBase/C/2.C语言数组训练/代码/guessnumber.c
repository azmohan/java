/************************************************************************/
/* 猜数字游戏                                                           */
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num[4]; //全局变量，用来保存生成的数字

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
	int right=0;//位置正确
	int wrong=0;//位置不正确但数字猜对
	int userdata[4];//保存用户输入的数据
	int i;
	int j;
	int guesscnt=0;//猜测的次数
	creatNum();

	while(guesscnt<10)
	{
		printf("请输入4个0-9之间的数字\n");
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
		printf("抱歉，你猜测的次数已经等于10次了！\n");
	}

	return 0;


}
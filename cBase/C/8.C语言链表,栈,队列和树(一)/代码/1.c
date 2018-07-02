/*学生管理系统*/
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#define		LIST_SUCCESS 0
#define		LIST_ERROR	-1

typedef struct student
{
	char name[20];
	int chinese; //语文成绩
	int math; //数学成绩
	struct student* next;
} STU;



//初始化list，第一个节点不用来存放数据
int init_list(STU** head)
{
	if( NULL!=*head )
	{
		printf("链表初始化错误！\n");
		return LIST_ERROR;
	}
	*head=(STU*)malloc(sizeof(STU));
	if( NULL==*head )
	{
		printf("分配空间出错！\n");
		return LIST_ERROR;
	}
	(*head)->next=NULL;
	printf("初始化完毕！\n");
	return LIST_SUCCESS;
}
//向list策插入节点元素
int insert_node(STU* stu, STU* head)
{
	if( NULL==head )
	{
		printf("链表还没有初始化，无法插入节点！\n");
		return LIST_ERROR;
	}
	while(NULL!=head->next)
	{
		head=head->next;
	}
	head->next=(STU*)malloc(sizeof(STU));
	if( NULL==head )
	{
		printf("分配内存错误！\n");
		return LIST_ERROR;
	}
	head=head->next;
	strncpy(head->name, stu->name, 20);
	head->chinese=stu->chinese;
	head->math=stu->math;
	head->next=NULL;
	printf("插入节点成功！\n");

	return LIST_SUCCESS;
}
//按数学成绩递增的顺序插入节点元素
int insert_node_sorted(STU* stu, STU* head)
{
	if( NULL==head )
	{
		printf("链表还没有初始化，无法插入节点！\n");
		return LIST_ERROR;
	}
	STU* pPre=head;
	STU* pCur=pPre->next;
	STU* new=(STU*)malloc(sizeof(STU));
	strncpy(new->name, stu->name, 20);
	new->chinese=stu->chinese;
	new->math=stu->math;
	while(NULL!=pCur)
	{
		if( new->math>=pCur->math )
		{
			pPre->next=new;
			new->next=pCur;
			return LIST_SUCCESS;
		}
		pPre=pCur;
		pCur=pCur->next;
	}
	pPre->next=new;
	new->next=NULL;
	return LIST_SUCCESS;
}
//删除节点，以学生名字匹配
int remove_node(const char* name, STU* head)
{
	STU* temp;
	if( NULL==head )
	{
		printf("链表还没有初始化，无法删除节点！\n");
		return LIST_ERROR;
	}
	while( NULL!=head->next )
	{
		if( 0==strcmp(head->next->name, name) )
		{
			temp=head->next;
			head->next=head->next->next;
			free(temp);
			printf("删除节点成功！\n");
			return LIST_SUCCESS;
		}
		head=head->next;
	}
	printf("没有找到要删除的节点！\n");
	return LIST_ERROR;
}
//遍历链表，返回匹配到的节点
STU* travel_list(const char* name, STU*head)
{
	if( NULL==head )
	{
		printf("链表还没有初始化，无法遍历链表！\n");
		return NULL;

	}
	while( NULL!=head->next )
	{
		if( 0==strcmp(head->next->name, name) )
		{
			return head->next;
		}
		head=head->next;
	}
	return NULL;
}
int delete_list(STU** head)
{
	STU* tmp;
	while( NULL!=*head )
	{
		tmp=*head;
		*head=(*head)->next;
		free(tmp);
	}
	printf("删除链表成功！\n");
	return LIST_SUCCESS;
}
int display_list(STU* head)
{
	if( NULL==head )
	{
		printf("链表还没有初始化，无法打印节点信息！\n");
		return LIST_ERROR;
	}
	if( NULL==head->next )
	{
		printf("链表为空，无法打印节点信息！\n");
		return LIST_ERROR;
	}
	while( NULL!=head->next )
	{
		printf("------------------------------>\n");
		printf("%s  %-4d%-4d\n", head->next->name, head->next->chinese, head->next->math);
		head=head->next;
	}
	return LIST_ERROR;
}
int invert_list(STU* head)
{
	STU* pPre;
	STU* pCur;
	STU* pNext;
	if( NULL==head->next || NULL==head || NULL==head->next->next)
	{
		printf("无法逆置链表！\n");
		return LIST_ERROR;
	}
	pCur=head->next;
	pNext=pCur->next;
	pCur->next=NULL;
	pPre=pCur;
	pCur=pNext;
	while( NULL!=pCur )
	{
		pNext=pCur->next;
		pCur->next=pPre;
		pPre=pCur;
		pCur=pNext;

	}
	head->next=pPre;
	return LIST_SUCCESS;
}
int main(int argc, char *argv[])
{
	int Quite=0;
	int choice;
	char name[20];
	STU* pHead=NULL;
	STU stu;
	STU* pstu=NULL;
	while(1)
	{
		printf("****************************************\n");
		printf("1、初始化链表请输入	1\n");
		printf("2、插入节点请输入	2\n");
		printf("3、删除节点请输入	3\n");
		printf("4、查找节点请输入	4\n");
		printf("5、删除链表请输入	5\n");
		printf("6、逆置链表请输入	6\n");
		printf("6、退出请输入		7\n");
		printf("****************************************\n");
		scanf("%d", &choice);
		switch ( choice )
		{
		case 1 :
			init_list(&pHead);
			break;
		case 2 :
			printf("请输入学生的姓名、语文成绩、数学成绩：\n");
			scanf("%s%d%d", stu.name, &stu.chinese, &stu.math);
			insert_node_sorted(&stu, pHead);
			printf("插入节点后链表的内容为：\n");
			display_list(pHead);
			break;
		case 3:
			printf("请输入你要删除节点的学生的名字：\n");
			scanf("%s", name);
			remove_node(name, pHead);
			printf("删除节点后，链表的内容为：\n");
			display_list(pHead);
			break;
		case 4:
			printf("请输入你要查找节点的学生的名字：\n");
			scanf("%s", name);
			pstu=travel_list(name, pHead);
			if( NULL==pstu )
			{
				printf("没有查到你所需要的信息！\n");
			}
			else
			{
				printf("你所查学生的信息为：\n");
				printf("%s  %-4d%-4d\n", pstu->name, pstu->chinese, pstu->math);
			}
			break;
		case 5:
			delete_list(&pHead);
			break;
		case 6:
			printf("逆置前链表内容为：\n");
			display_list(pHead);
			if(LIST_SUCCESS==invert_list(pHead))
			{
				printf("逆置后链表内容为：\n");
				display_list(pHead);
			}
			break;
		case 7:
			Quite=1;
			break;
		default :
			break;
		}
		if( 1==Quite )
		{
			break;
		}
	}
	return 0;
}

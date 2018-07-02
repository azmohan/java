/*ѧ������ϵͳ*/
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#define		LIST_SUCCESS 0
#define		LIST_ERROR	-1

typedef struct student
{
	char name[20];
	int chinese; //���ĳɼ�
	int math; //��ѧ�ɼ�
	struct student* next;
} STU;



//��ʼ��list����һ���ڵ㲻�����������
int init_list(STU** head)
{
	if( NULL!=*head )
	{
		printf("�����ʼ������\n");
		return LIST_ERROR;
	}
	*head=(STU*)malloc(sizeof(STU));
	if( NULL==*head )
	{
		printf("����ռ����\n");
		return LIST_ERROR;
	}
	(*head)->next=NULL;
	printf("��ʼ����ϣ�\n");
	return LIST_SUCCESS;
}
//��list�߲���ڵ�Ԫ��
int insert_node(STU* stu, STU* head)
{
	if( NULL==head )
	{
		printf("����û�г�ʼ�����޷�����ڵ㣡\n");
		return LIST_ERROR;
	}
	while(NULL!=head->next)
	{
		head=head->next;
	}
	head->next=(STU*)malloc(sizeof(STU));
	if( NULL==head )
	{
		printf("�����ڴ����\n");
		return LIST_ERROR;
	}
	head=head->next;
	strncpy(head->name, stu->name, 20);
	head->chinese=stu->chinese;
	head->math=stu->math;
	head->next=NULL;
	printf("����ڵ�ɹ���\n");

	return LIST_SUCCESS;
}
//����ѧ�ɼ�������˳�����ڵ�Ԫ��
int insert_node_sorted(STU* stu, STU* head)
{
	if( NULL==head )
	{
		printf("����û�г�ʼ�����޷�����ڵ㣡\n");
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
//ɾ���ڵ㣬��ѧ������ƥ��
int remove_node(const char* name, STU* head)
{
	STU* temp;
	if( NULL==head )
	{
		printf("����û�г�ʼ�����޷�ɾ���ڵ㣡\n");
		return LIST_ERROR;
	}
	while( NULL!=head->next )
	{
		if( 0==strcmp(head->next->name, name) )
		{
			temp=head->next;
			head->next=head->next->next;
			free(temp);
			printf("ɾ���ڵ�ɹ���\n");
			return LIST_SUCCESS;
		}
		head=head->next;
	}
	printf("û���ҵ�Ҫɾ���Ľڵ㣡\n");
	return LIST_ERROR;
}
//������������ƥ�䵽�Ľڵ�
STU* travel_list(const char* name, STU*head)
{
	if( NULL==head )
	{
		printf("����û�г�ʼ�����޷���������\n");
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
	printf("ɾ������ɹ���\n");
	return LIST_SUCCESS;
}
int display_list(STU* head)
{
	if( NULL==head )
	{
		printf("����û�г�ʼ�����޷���ӡ�ڵ���Ϣ��\n");
		return LIST_ERROR;
	}
	if( NULL==head->next )
	{
		printf("����Ϊ�գ��޷���ӡ�ڵ���Ϣ��\n");
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
		printf("�޷���������\n");
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
		printf("1����ʼ������������	1\n");
		printf("2������ڵ�������	2\n");
		printf("3��ɾ���ڵ�������	3\n");
		printf("4�����ҽڵ�������	4\n");
		printf("5��ɾ������������	5\n");
		printf("6����������������	6\n");
		printf("6���˳�������		7\n");
		printf("****************************************\n");
		scanf("%d", &choice);
		switch ( choice )
		{
		case 1 :
			init_list(&pHead);
			break;
		case 2 :
			printf("������ѧ�������������ĳɼ�����ѧ�ɼ���\n");
			scanf("%s%d%d", stu.name, &stu.chinese, &stu.math);
			insert_node_sorted(&stu, pHead);
			printf("����ڵ�����������Ϊ��\n");
			display_list(pHead);
			break;
		case 3:
			printf("��������Ҫɾ���ڵ��ѧ�������֣�\n");
			scanf("%s", name);
			remove_node(name, pHead);
			printf("ɾ���ڵ�����������Ϊ��\n");
			display_list(pHead);
			break;
		case 4:
			printf("��������Ҫ���ҽڵ��ѧ�������֣�\n");
			scanf("%s", name);
			pstu=travel_list(name, pHead);
			if( NULL==pstu )
			{
				printf("û�в鵽������Ҫ����Ϣ��\n");
			}
			else
			{
				printf("������ѧ������ϢΪ��\n");
				printf("%s  %-4d%-4d\n", pstu->name, pstu->chinese, pstu->math);
			}
			break;
		case 5:
			delete_list(&pHead);
			break;
		case 6:
			printf("����ǰ��������Ϊ��\n");
			display_list(pHead);
			if(LIST_SUCCESS==invert_list(pHead))
			{
				printf("���ú���������Ϊ��\n");
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

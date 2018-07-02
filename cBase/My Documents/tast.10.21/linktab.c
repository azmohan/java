#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERROR   0;
#define SUCCESS 1;

#ifdef DB
    #define DEBUG(format,...)printf(format,##__VA_ARGS__)
#else
    #define DEBUG(format,...)do{}while(0)
#endif

typedef int status;

/*创建链表基础模型*/
typedef struct student
{
    int id;
    char name[20];
    int xing;
    int age;
    struct student* next;
}DATA;


/*创建链表头*/
status initlist(DATA** phead)
{
    if(NULL!=*phead)
    {
     DEBUG("in %s,*phead is not NULL!\n",__FUNCTION__);
     return ERROR;
    }
    *phead=(DATA*)malloc(sizeof(DATA));
    if(NULL==*phead)
    {
        DEBUG("in %s,malloc error!\n",__FUNCTION__);
        return ERROR;
    }
    memset(*phead,0,sizeof(DATA));
    return 0;
}


/*插入新链表*/

status insertnode(DATA* phead,DATA* e)
{
    if(NULL==phead)
    {
        DEBUG("in %s,*phead is NULL!\n",__FUNCTION__);
        return ERROR;
    }
    while(phead->next!=NULL)
    {
        phead=phead->next;
    }
    phead->next=(DATA*)malloc(sizeof(DATA));
    if(NULL==phead->next)
    {
        DEBUG("in %s,malloc error!\n",__FUNCTION__);
        return ERROR;
    }
    phead=phead->next;
    memcpy(phead,e,sizeof(DATA));
    phead->next=NULL;
    return SUCCESS;
}




/*删除学号的学生*/
status delnode(DATA* phead,int del)
{
    DATA* pdel=NULL;

    while(phead->next != NULL)
    {
        if(phead->next->id==del)
        {
              pdel=phead->next;
              phead->next=pdel->next;
              free(pdel);
              pdel=NULL;
        }
        if(phead->next !=NULL)
        {
            phead=phead->next;
        }
        
    }
    return SUCCESS;
}



/*修改学生信息*/
int changelist(DATA* phead,int old,int new)
{
    while(phead->next != NULL)
    {
        if(phead->next->id==old)
        {
            phead->next->id=new;
        }
        phead=phead->next;
    }
}


/*输出学生信息*/
void display(DATA* phead)
{
    
    
    while(phead->next != NULL)
    {
        printf("%d\t\t%s\t\t%d\t\t%d\t\n",phead->next->id,phead->next->name,phead->next->xing,phead->next->age);
        phead=phead->next;
    }
}

/*删除链表*/
status dellist(DATA**phead)
{
    DATA* p=*phead;
    *phead=NULL;
    DATA* pnext=p->next;
    while(p!=NULL)
    {
        free(p);
        p=pnext;
        if(p!=NULL)
        {
            pnext=p->next;
        }
    }
    return SUCCESS;
}




/*查找学生信息*/



void dismessage(DATA* tmp,DATA* phead,int* halt)
{
    int keyval;
    int id,idd,iddd;

    printf("********************学生成绩管理系统**********************\n");
    printf("1--添加\n");
    printf("2--删除\n");
    printf("3--打印\n");
    printf("4--退出\n");
    printf("5--查找\n");
    printf("6--修改\n");
    printf("7--删表\n");
    printf("**********************************************************\n");
    printf("请输入选择项目:");
    scanf("%d",&keyval);
    while(keyval > 7 || keyval < 0)
    {
     printf("非法输入！\n");
     printf("输入选择项目1～4\n");
     scanf("%d",&keyval);
    }
    switch(keyval)
    {
        case 1:
            printf("请输入学生学号名\n");
            scanf("%d",&(tmp->id));
            printf("请输入学生名字\n");
            scanf("%s",tmp->name);
            printf("请输入学生性别\n");
            scanf("%d",&(tmp->xing));
            printf("请输入学生年龄\n");
            scanf("%d",&(tmp->age));
            insertnode(phead,tmp);
            break;
        case 2:
            printf("请输入要删除学生学号\n");
            scanf("%d",&id);
            delnode(phead,id);
            break;
        case 3:
            printf("学号\t\t姓名\t\t性别\t\t年龄\n");
            display(phead);
            break;
        case 4:
            *halt=0;
            
        case 5:
            break;
        case 6:
            printf( "请输入要修改的学号：" );
            scanf( "%d",&idd);
            printf( "请输入修改后的学号" );
            scanf("%d",&iddd );
            changelist(phead,idd,iddd);
            display(phead);
        case 7:
            dellist(&phead);
            break;
                
            
            

        default:
            break;
    }
}
int main()
{
    DATA* phead=NULL;
    DATA tmp,e;
    int halt=1;
     

    initlist(&phead);
    
    
    
    display(phead);
    while(halt)
    {
        dismessage(&tmp,phead,&halt);
    }

    return 0;
}



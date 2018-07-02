/*头文件*/
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

/*定义字符常量*/
#define SUCCESS      0
#define ERROR       -1
#define MALE         0
#define FEMALE       1

/*调试开关*/
#ifdef  DB
    #define DEBUG(format, ...)   printf(format, ##__VA_ARGS__)
#else
    #define DEBUG(format, ...)  do{}    while(0)
#endif

/*结构定义(学生信息)*/
typedef struct node{
    int id ;   /*学生的学号*/
    char name[20];  /*学生的姓名*/
    int sex;  /*学生的性别*/
    int age;  /*学生的年龄*/
    struct node *next;
} NODE;

typedef int state;  /*把state定义成int类型*/


/*函数原型*/
state initList(NODE** plistHead);   /*初始化学生信息链表*/
state insertNode(NODE* plistHead,NODE* student); /*在链表中插入节点，一个学生的信息*/
void displaymessage(NODE* plistHead,NODE* tmp,int* halt);   /*显示信息*/
state displayNode(NODE* plistHead); /*阅历学生信息链表*/
//state findNode();   /*查找一个学生的信息*/
//state changeNode(); /*修改某个学生的信息*/
state delNode(NODE* plistHead,int id);    /*在学生信息链表中删除某个学生信息*/
state delList(NODE** plistHead);    /*删除学生信息链表*/


/*程序从这里开始*/
int main(int argc, char *argv[])
{
    NODE student,tmp;
    NODE *plistHead = NULL;
    int i;
    int halt = 1;
    
    
    initList(&plistHead);
    while(halt)
    {
        displaymessage(plistHead,&tmp,&halt);
    }
    displayNode(plistHead);

    

    return 0;
}

/*初始化学生信息链表*/
state initList(NODE** plistHead)
{
    if(NULL != *plistHead)  /*如果*plistHead不是NULL, 不允许用其作首地址创建链表*/
    {
        DEBUG("in %s,*plistHead is NULL,building list is unlawyer!\n",__FUNCTION__);
        return ERROR;
    }
    *plistHead = (NODE*)malloc(sizeof(NODE));   /*为指针分配内存空间*/
    if("NULL == *plistHead")
    {
        DEBUG("in %s,malloc is not successful!\n",__FUNCTION__);
        return ERROR;
    }
    memset(*plistHead,0,sizeof(NODE));  /*初始化为指针分配的内存空间*/
    return SUCCESS;
}

/*插入某个学生信息*/
state insertNode(NODE* plistHead,NODE* student)
{
    if(NULL == plistHead )
    {
        DEBUG("in %s,plistHead is NULL,is not initiable!\n",__FUNCTION__);
        return ERROR;
    }
    while(NULL != plistHead->next)
        plistHead = plistHead->next;
    plistHead->next = (NODE*)malloc(sizeof(NODE));
    if(NULL == plistHead)
    {
        DEBUG("in %s,malloc is not successful!\n",__FUNCTION__);
        return ERROR;
    }
    plistHead = plistHead->next;
    memcpy(plistHead,student,sizeof(NODE));
    plistHead->next = NULL;
    return SUCCESS;
}

/*删除某个学生的信息*/
state delNode(NODE* plistHead,int id)    
{
    NODE* pdel = NULL;
    if(NULL == plistHead)
    {
        DEBUG("in %s,plistHead is NULL,list is not built!\n",__FUNCTION__);
        return ERROR;
    }
    while(NULL != plistHead->next)
    {
        if(id == plistHead->next->id)
        {
            pdel = plistHead->next;
            plistHead->next = pdel->next;
            free(pdel);
            pdel = NULL;
        }
        if(NULL != plistHead->next)
            plistHead = plistHead->next;
    }
    return SUCCESS;
}

/*删除学生信息链表*/
state delList(NODE** plistHead)
{
    NODE* p = *plistHead;
    NODE* pnext = p->next;

    if(NULL == *plistHead)
    {
        DEBUG("in %s,*plistHead is NULL,list is not built!\n",__FUNCTION__);
        return ERROR;
    }
    *plistHead = NULL;
    while(NULL != p)
    {
        free(p);
        p = pnext;
        if(NULL != p)
            pnext = p->next;
    }
    return SUCCESS;
}

/*阅历学生信息链表*/
state displayNode(NODE* plistHead)
{
    if(NULL == plistHead)
    {
        DEBUG("in %s,plistHead is NULL,list is not built!\n",__FUNCTION__);
        return ERROR;
    }
    while(NULL != plistHead->next)
    {
        printf("\n");
        printf("**********************************\n");
        printf("学号：%-3d\n",plistHead->next->id);
        printf("姓名：%-3s\n",plistHead->next->name);
        if(MALE == plistHead->next->sex)
            printf("性别：男\n");
        else if("FEMALE == plistHead->next->sex")
            printf("性别：女\n");
        else
            printf("性别输入有误！\n");

        printf("年龄：%-3d\n",plistHead->next->age);
        plistHead = plistHead->next;
    }
    printf("\n");
    printf("**********************************\n");
    
}


/*显示操作信息*/
void displaymessage(NODE* plistHead,NODE* tmp,int* halt)
{
    int keyval;
    int id,idd,iddd;

    printf("****************学生信息系统******************\n");
    printf("1--添加\n");
    printf("2--删除\n");
    printf("3--打印\n");
    printf("4--退出\n");
    printf("5--查找\n");
    printf("6--修改\n");
    printf("7--删表\n");
    printf("**********************************************\n");
    printf("请输入你选择的项目:");
    scanf("%d",&keyval);
    while(keyval > 7 || keyval < 0)
    {
        printf("非法输入！\n");
        printf("请选择项目1～7:\n");
        scanf("%d",&keyval);
    }
    switch(keyval)
    {
        case 1:
            printf("请输入学生的学号：\n");
            scanf("%d",&(tmp->id));
            printf("请输入学生的姓名：\n");
            scanf("%s",(tmp->name));
            printf("请输入学生的性别：\n");
            scanf("%d",&(tmp->sex));
            printf("请输入学生的年龄：\n");
            scanf("%d",&(tmp->age));
            insertNode(plistHead,tmp);
            break;
        case 2:
            printf("请输入要删除学生的学号：\n");
            scanf("%d",&id);
            delNode(plistHead,id);
            break;
        case 3:
            break;
        case 4:
            *halt = 0;
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            delList(&plistHead);
            break;
        default:
            break;

    }
    
}

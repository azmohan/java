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

typedef struct student
{
    char name[20];
    char sex[10];
    int  num;
    int  age;
    int  chinese;
    int  math;
    struct student* next;
}DATA;

status initlist(DATA** phead)
{
    if(NULL!=*phead)
    {
     DEBUG ("in %s,*phead is not NULL!\n",__FUNCTION__);
     return ERROR;
    } 
    *phead=(DATA*)malloc(sizeof(DATA));
    if(NULL==*phead)
    {
        DEBUG("in %s,malloc error!\n",__FUNCTION__);
        return ERROR; printf("姓名\t\t性别\t\t学号\t\t年龄\t\t语文成绩\t\t数学成绩\n");

    }
    memset(*phead,0,sizeof(DATA));
    return 0;
}

status insertnode(DATA* phead,DATA* e)
{
    if(NULL==phead)
    {
        DEBUG("in %s,*phead is NULL!\n",__FUNCTION__);
        return ERROR;
    } 
    while(phead->next!=NULL)
    { printf("姓名\t\t性别\t\t学号\t\t年龄\t\t语文成绩\t\t数学成绩\n");

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

status delnode(DATA* phead,int num)
{
    DATA* temp=NULL;

    if(NULL==phead)
    {
        DEBUG("in %s,the phead is NULL!\n",__FUNCTION__);
        return ERROR;
    }
    //while(phead->next!=NULL)
   // {
    while(phead->num!=num)
    {
        temp=phead;// 暂时放的是上个节点的位置
        phead=phead->next;
    }
    temp->next=phead->next;
    free(phead);
    phead=phead->next;
   // }
}

status display(DATA* phead)
{
    if(phead==NULL)
    {
        DEBUG("in %s,display phead error!\n",__FUNCTION__);
        return ERROR;
    }
    while(phead->next != NULL)
    {
        printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\n",phead->next->name,phead->next->sex,phead->next->num,
        phead->next->age, phead->next->chinese,phead->next->math);
        phead=phead->next;
    }
    return SUCCESS;
}
/**********按照num号来查找并显示出来******/
status findnode(DATA* phead,int num)
{
    if(phead==NULL)
    {
        DEBUG("in %s,phead is NULL!\n",__FUNCTION__);
        return ERROR;
    }
    while(phead->next!=NULL)
    {
        if(phead->next->num==num)
        {
        printf("姓名\t\t学号\t\t语文成绩\t\t数学成绩\n");
        printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\n",phead->next->name,
        phead->next->sex,phead->next->num,phead->next->age,phead->next->chinese,phead->next->math);
        }
        phead=phead->next;
    }
    return SUCCESS;
}
/************************************************/

/************************************************/
status modefindnode(DATA* phead,int mode)
{
    DATA e;

    if(phead==NULL)
    {
        DEBUG("in %s,phead is NULL!\n",__FUNCTION__);
        return ERROR;
    }
    printf("查找的结果如下：\n");
    printf("姓名\t\t性别\t\t学号\t\t年龄\t\t语文成绩\t\t数学成绩\n\n");
    switch(mode)
    {
        case 1:
                printf("请输入查找学生姓名:");
                scanf("%s",e.name);
                while(phead->next!=NULL)
                {         
                if(strcmp(phead->next->name,e.name)==0)
                {
                     printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\n",phead->next->name,
                     phead->next->sex,phead->next->num,phead->next->age,phead->next->chinese,phead->next->math);
                }
                phead=phead->next;
                }
                break;
        case 2:
                
                printf("请输入查找学生性别:");
                scanf("%s",e.sex);
                while(phead->next!=NULL)
                {
                if(strcmp(phead->next->sex,e.sex)==0)
                {
                     printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\n",phead->next->name,
                     phead->next->sex,phead->next->num,phead->next->age,phead->next->chinese,phead->next->math);
                }
                phead=phead->next;
                }
                break;
        case 3:
                
                printf("请输入查找学生学号:");
                scanf("%d",&(e.num));
                while(phead->next!=NULL)
                {
                if(phead->next->num==e.num)
                {
                    printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\n",phead->next->name,
                    phead->next->sex,phead->next->num,phead->next->age,phead->next->chinese,phead->next->math);

                }
                phead=phead->next;
                }
                break;
        case 4:
                printf("请输入查找学生年龄:");
                scanf("%d",&(e.age));
                while(phead->next!=NULL)
                {
                if(phead->next->age==e.age)
                {
                    printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\n",phead->next->name,
                    phead->next->sex,phead->next->num,phead->next->age,phead->next->chinese,phead->next->math);

                }
                phead=phead->next;
                }
                break;
       // case 5:
              //  break;
          case 6:return;
        default:
                printf("查找的模式错误!\n");
                return ERROR;
    }
}
/************************************************/


status modifynode(DATA* phead,int num,int modify)
{
    DATA a;
    if(phead==NULL)
    {
        DEBUG("in %s,phead is NULL!\n",__FUNCTION__);
        return ERROR;
    }
    while(phead->next!=NULL)
    {
        if(phead->next->num==num)
        {
            switch(modify)
            {
                case 1:
                    printf("输入修改后的姓名:");
                    scanf("%s",a.name);
                    strcpy(phead->next->name,a.name);
                    break;
                case 2:
                    printf("输入修改后的性别:");
                    scanf("%s",phead->next->sex);
                   // strcpy(phead->next->sex,a.sex);
                    break;
                case 3:
                    printf("输入修改后的学号:");
                    scanf("%d",&(phead->next->num));
                    break;
                case 4:
                    printf("输入修改后的年龄:");
                    scanf("%d",&(phead->next->age));
                    break;
                case 5:break;
                default:break;
            }
        }
        phead=phead->next;
    }
    return SUCCESS;
}
/*****************************************************************/
status getfindmode(void)
{
    int mode;
    printf("********************************************************************************************************\n");
    printf("1--按姓名查找\n");
    printf("2--按性别查找\n");
    printf("3--按学号查找\n");
    printf("4--按年龄查找\n");
    printf("5--按成绩查找\n");
    printf("6--退出查找\n");
    printf("********************************************************************************************************\n");
    printf("输入你选择的查找模式:");
    scanf("%d",&mode);
    printf("********************************************************************************************************\n");
    
    return mode;
}
/*****************************************************************/
void inputinfo(DATA *tmp)
{
     printf("请输入学生姓名\n");
     scanf("%s",tmp->name);
     printf("请输入学生性别\n");
     scanf("%s",tmp->sex);
     printf("请输入学生学号\n");
     scanf("%d",&(tmp->num));
     printf("请输入学生年龄\n");
     scanf("%d",&(tmp->age));
     printf("请输入学生语文成绩\n");
     scanf("%d",&(tmp->chinese));
     printf("请输入学生数学成绩\n");
     scanf("%d",&(tmp->math));
}
/**********************************************************************************************************************/
status filewrite(DATA* phead)
{
    DATA e;
    FILE* fw=fopen("student","w+");
    if(NULL==fw)
    {
        DEBUG("in %s,fw open error!\n",__FUNCTION__);
        return ERROR;
    }
    do
    {
        phead=phead->next;
       // memcpy(&e,
        fwrite(phead,sizeof(DATA),1,fw);
    }
    while(phead->next!=NULL);

    return SUCCESS;
}
    
/**********************************************************************************************************************/
/**********************************************************************************************************************/
status initfileread(DATA* phead)
{
    DATA e;
    FILE* fr=fopen("student","r");
    if(fr==NULL)
    {
        DEBUG("in %s,read file is error!",__FUNCTION__);
        return ERROR;
    }

    int ret;
    while(ret=fread(&e,sizeof(DATA),1,fr))
    {
        DEBUG("ret=%d\n", ret);
        phead->next=(DATA*)malloc(sizeof(DATA));
        if(phead->next==NULL)
        {
            DEBUG("in %s,malloc is error!\n",__FUNCTION__);
            return ERROR;
        }
         memcpy(phead->next,&e,sizeof(DATA));
       //  phead->next->next=NULL;//保存文件的时候会将每个节点的所有信息都保存到文件中，因此读文件的时候会将那个地址给读出
         phead=phead->next;
    }
        phead->next=NULL;//保存文件的时候会将每个节点的所有信息都保存到文件中，因此读文件的时候会将那个地址给读出
    return SUCCESS;
}



/**********************************************************************************************************************/

void dismessage(DATA* tmp,DATA* phead,int* halt)
{
    int keyval;
    int num,modify;
    int fnum,flag=0;
    char i;
    printf("*********************************************学生成绩管理系统*******************************************\n");
    printf("1--添加\n");
    printf("2--删除\n");
    printf("3--打印\n");
    printf("4--退出\n");
    printf("5--查找\n");
    printf("6--修改\n");
    printf("7--保存\n");
    printf("********************************************************************************************************\n");
    printf("请输入选择项目:");
    scanf("%d",&keyval);
    printf("********************************************************************************************************\n");
    while(keyval > 7 || keyval < 0)
    {
     printf("   非法输入！\n");
     printf("输入选择项目1～6\n");
     scanf("%d",&keyval);
    }
    switch(keyval)
    {
        case 1:
            inputinfo(tmp);
            insertnode(phead,tmp);
            break;
        case 2:
            printf("请输入要删除学生学号\n");
            scanf("%d",&num);
            delnode(phead,num);
            break;
        case 3:
            printf("姓名\t\t性别\t\t学号\t\t年龄\t\t语文成绩\t\t数学成绩\n");
            display(phead);
            break;
        case 4:
            *halt=0;
            filewrite(phead);
             return;
        case 5:
            printf("请输入要查找学生的信息按提示输入\n");
            fnum=getfindmode();
            modefindnode(phead,fnum);
            break;
        case 6:
            printf("请输入要修改的学生学号:");
            scanf("%d",&num);
            printf("1--修改学生姓名\n");
            printf("2--修改学生性别\n");
            printf("3--修改学生学号\n");
            printf("4--修改学生年龄\n");
            printf("5--修改学生成绩\n");
            printf("6--退出修改\n");
            printf("输入你选择:");
            scanf("%d",&modify);
            modifynode(phead,num,modify);  
            break;
        case 7:
            filewrite(phead);
            break;
        default:
            break;
     }
}
int main()
{
    DATA* phead=NULL;
    DATA tmp;
    int halt=1;

    initlist(&phead);
    initfileread(phead);
    while(halt)
    {
        dismessage(&tmp,phead,&halt);
    }
    return 0;
}



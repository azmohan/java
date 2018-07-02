#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <stdbool.h>
#define     SUCCESS     0
#define     ERROR       -1
typedef int status;
#ifdef DB
    #define     DEBUG(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define     DEBUG(format, ...) do{}while(0)
#endif

typedef struct data
{
    int id;
    char name[20];
    bool man;
    int     age;
    struct data* next;
}DATA;

status initList(DATA** pHead)
{
    if(NULL!=*pHead)
    {
        DEBUG("in %s, *pHead is not NULL!\n", __FUNCTION__);
        return ERROR;
    }
    *pHead=(DATA*)malloc(sizeof(DATA));
    if(NULL==*pHead)
    {
        DEBUG("in %s, malloc error!\n", __FUNCTION__);
        return ERROR;
    }
    memset(*pHead, 0, sizeof(DATA));
    //(*phead)->next=NULL;
    return SUCCESS;
}

status insertNode(DATA* pHead, DATA* e)
{
    if(NULL==pHead)
    {
        DEBUG("in %s, pHead is NULL!\n", __FUNCTION__);
        return ERROR;
    }

    while(pHead->next!=NULL)
    {
        pHead=pHead->next;
    }
    pHead->next=(DATA*)malloc(sizeof(DATA));

    if(NULL==pHead->next)
    {
        DEBUG("in %s, malloc error!\n", __FUNCTION__);
        return ERROR;
    }
    pHead=pHead->next;
    memcpy(pHead, e, sizeof(DATA));
    pHead->next=NULL;

    return SUCCESS;

}

status displayNode(DATA* e)
{
    printf("id:%d\nname:%s\nsex:%s\nage:%d\n", e->id, e->name, (e->man? "male":"female"), e->age);
    printf("\n");
}

status displayList(DATA* pHead)
{
    if(NULL==pHead)
    {
        DEBUG("in %s, pHead is NULL!\n", __FUNCTION__);
        return ERROR;
    }
    while(pHead->next!=NULL)
    {
        displayNode(pHead->next);
        pHead=pHead->next;
    }
    return SUCCESS;
}

status changeNode(DATA* pHead, DATA* e)
{
    DATA* p=NULL;
    if(NULL==pHead)
    {
        DEBUG("in %s, pHead is NULL!\n", __FUNCTION__);
        return ERROR;
    }
    bool flag=false;
    while(pHead->next!=NULL)
    {
        if(e->id==pHead->next->id)
        {
            flag=true;
            p=pHead->next->next;
            memcpy(pHead->next, e, sizeof(DATA));
            pHead->next->next=p;
            return SUCCESS;
        }
        pHead=pHead->next;
    }
    return ERROR;
}

status delNode(DATA* pHead, int id)
{
    DATA* pDel=NULL;
    bool flag=false;
    if(NULL==pHead)
    {
        DEBUG("in %s, pHead is NULL!\n", __FUNCTION__);
        return ERROR;
    }

    while(pHead->next!=NULL)
    {
        if(id==pHead->next->id)
        {
            flag=true;
            pDel=pHead->next;
            pHead->next=pDel->next;
            free(pDel);
            pDel=NULL;
        }
        if(NULL!=pHead->next)
        {
            pHead=pHead->next;
        }
    }
    if(flag)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}
status delList(DATA** pHead)
{
    if(*pHead==NULL)
    {
        DEBUG("in %s, *pHead is NULL!\n", __FUNCTION__);
        return ERROR;
    }

    DATA* p=*pHead;
    *pHead=NULL;
    DATA* pNext=p->next;
    while(p!=NULL)
    {
        free(p);
        p=pNext;
        if(p!=NULL)
        {
            pNext=p->next;
        }
    }
    return SUCCESS;
}

DATA* findNode0(DATA* pHead, int id)
{
    if(pHead==NULL)
    {
        DEBUG("in %s, pHead is NULL!\n", __FUNCTION__);
        return NULL;
    }
    while(pHead->next!=NULL)
    {
        if(id==pHead->next->id)
        {
            return pHead->next;
        }
        pHead=pHead->next;
    }
    return NULL;
}

DATA* findNode1(DATA* pHead, const char* name)
{
    if(pHead==NULL)
    {
        DEBUG("in %s, pHead is NULL!\n", __FUNCTION__);
        return NULL;
    }
    while(pHead->next!=NULL)
    {
        if(0==strcmp(pHead->next->name, name))
        {
            return pHead->next;
        }
        pHead=pHead->next;
    }
    return NULL;
}

DATA* findNode2(DATA* pHead, bool b)
{
    if(pHead==NULL)
    {
        DEBUG("in %s, pHead is NULL!\n", __FUNCTION__);
        return NULL;
    }
    while(pHead->next!=NULL)
    {
        if(b==pHead->next->man)
        {
            return pHead->next;
        }
        pHead=pHead->next;
    }
    return NULL;

}



int main(int argc, char *argv[])
{
    DATA* pListHead=NULL;
    DATA  e;
    initList(&pListHead);
    DATA a[3]={{1, "Zhang San", true, 20}, {2, "Li Si", true, 21}, {3, "Li Mei", false, 22} };

    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
        insertNode(pListHead, &a[i]);

    }
    displayList(pListHead);
    e.id=1;
    strcpy(e.name, "Zhang San");
    e.man=true;
    e.age=23;
    /*int ret=changeNode(pListHead, &e);
    if(ERROR==ret)
    {
        DEBUG("can not find the node!\n");
    }
    printf("after change:\n");
    displayList(pListHead);*/
    /*DATA* pdata=findNode0(pListHead, 2);
    if(NULL!=pdata)
    {
        printf("the node you find :\n");
        displayNode(pdata);
    }*/

    DATA* pdata=findNode1(pListHead, "Li Mei");
    if(NULL!=pdata)
    {
        printf("the node you find :\n");
        displayNode(pdata);
    }
    return 0;
}

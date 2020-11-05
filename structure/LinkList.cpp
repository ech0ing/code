#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;      //存放元素
    struct LNode *next; //指向后继节点
} LinkNode;             //单链表

void CreatListF(LinkNode *&L, ElemType a[], int n) //头插法
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;             //创建头节点,next域为NULL
    for (int i = 0; i < n; i++) //循环建立数据节点s
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];    //创建数据节点s
        s->next = L->next; //将结点s插入到原首节点之前,头节点之后
        L->next = s;
    }
}

void CreatListR(LinkNode *&L, ElemType a[], int n) //尾插法
{
    LinkNode *s, *r;                          //增加一个尾指针,使其一直指向链表的尾结点
    L = (LinkNode *)malloc(sizeof(LinkNode)); //创建头结点
    r = L;                                    //r始终指向尾结点,初始指向头结点
    for (int i = 0; i < n; i++)               //循环建立数据结点
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i]; //创建数据结点s
        r->next = s;    //将结点s插入到结点r之后
        r = s;
    }
    r->next = NULL; //尾结点的next域置为NULL
}

void InitList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void DestroyList(LinkNode *&L)
{
    LinkNode *pre = L, *p = L->next; //pre指向结点p的前驱结点
    while (p != NULL)                //扫描单链表L
    {
        free(pre); //释放pre结点
        pre = p;   //pre,p同步后移一个结点
        p = pre->next;
    }
    free(pre); //循环结束时p为NULL,pre指向尾结点,并释放它
}

bool ListEmpty(LinkNode *L)
{
    return (L->next == NULL);
}

int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L; //p指向头结点,n置为0(即头结点的序号为0)
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return (n);
}

void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL) //p不为空,则输出data
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

bool GetElem(LinkNode *L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L; //p指向头结点,j置为0
    if (i <= 0)
        return false;
    while (j < i && p != NULL) //找第i个结点p
    {
        j++;
        p = p->next;
    }
    if (p == NULL) //不存在第i个数据结点返回fasle
        return false;
    else //存在第i个数据结点返回true
    {
        e = p->data; //将找到的值赋给e
        return true;
    }
}

int LocateElem(LinkNode *L, ElemType e) //按值查找
{
    int i = 0;
    LinkNode *p = L->next;            //p指向首结点,i为1(即首节点的序号为1)
    while (p != NULL && p->data != e) //查找data值为e的结点,序号为i
    {
        p = p->next;
        i++;
    }
    if (p == NULL) //不存在值为e的结点则返回0
        return (0);
    else //存在值为e的结点,返回其逻辑序号i
        return (i);
}

//找到第i-1个结点,由p指向它,然后将值为e的结点s插入到p之后(即p->next)
bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL) //查找第i-1个结点p
    {
        j++;
        p = p->next;
    }
    if (p == NULL) //未找到第i-1个结点返回false
        return false;
    else //找到第i-1个结点p,插入新结点并返回true
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;       //创建新结点s,将其data域置为e
        s->next = p->next; //将s插入到p之后
        p->next = s;
        return true;
    }
}

bool ListDelet(LinkNode *&L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L, *q; //p指向头结点,j(头结点的序号)为0
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL) //查找第i-1个结点
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        q = p->next;   //找到第i-1个结点p,q指向第i个结点
        if (q == NULL) //不存在第i个结点则返回false
            return false;
        e = q->data;
        p->next = q->next; //从单链表中删除q结点
        free(q);
        return true; //表示成功删除q结点
    }
}

void ListSort(LinkNode *&L, int length) //冒泡排序
{
    LinkNode *p = L; //p指向头结点
    int temp, i, j;
    for (i = 0; i < length - 1; i++)
    {
        p = L->next;
        for (j = 0; j < length - 1; j++)
        {
            if (p->data > p->next->data) //如果p比它后面的数大,则交换位置
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next; //p指向下一个结点
        }
    }
}

int main()
{
    LinkNode *L;
    //实验一
    printf("实验一:\n");
    InitList(L);
    ElemType a[] = {1, 3, 2, 9, 0, 4, 7, 6, 5, 8};
    CreatListR(L, a, 10);

    printf("初始元素:");
    DispList(L);

    printf("删 除 后:");
    int e;                                 //存放删除的元素
    ListDelet(L, LocateElem(L, 2) + 1, e); //删除第一个值为2的元素
    DispList(L);

    printf("插 入 后:");
    ListInsert(L, 5, 2); //在5号位置插入2
    DispList(L);

    printf("排 序 后:");
    ListSort(L, ListLength(L));
    DispList(L);
    DestroyList(L);
    printf("\n");

    //实验二
    printf("实验二:\n");
    printf("整 理 后:");
    InitList(L);
    ElemType b[]={1,-3,-2,-9,0,4,7,-6,-5,8};
    CreatListR(L,b,10);
    ListSort(L,ListLength(L));
    DispList(L);
    return 0;
}

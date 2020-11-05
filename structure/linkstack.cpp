#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct linknode
{
    ElemType data;
    struct linknode *next;
} LinkStNode;

void InitStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

void DestoryStack(LinkStNode *&s)
{
    LinkStNode *pre =s, *p=s->next;
    while (p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

bool StackEmpty(LinkStNode *s){
    return(s->next==NULL);
}

void Push(LinkStNode*&s,ElemType e){
    LinkStNode *p;
    p=(LinkStNode *)malloc(sizeof(LinkStNode));

}

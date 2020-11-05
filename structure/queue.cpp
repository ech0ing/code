#include <stdio.h>
#include <stdlib.h>
#define QueueSize 20

typedef int ElemType;
typedef struct
{
    ElemType data[QueueSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

void DestoryQueue(SqQueue *&q)
{
    free(q);
}

bool QueueEmpty(SqQueue *q)
{
    return (q->front == q->rear);
}

bool enQueue(SqQueue *&q,ElemType e)
{
    if(q->rear==QueueSize-1) //上溢
        return false;
    q->rear++;
    q->data[q->rear]=e;
    return true;
}
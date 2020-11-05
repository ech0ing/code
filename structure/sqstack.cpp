#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1; //栈顶指针置为-1
}

void DestoryStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *s)
{
    return (s->top == -1);
}

bool Push(SqStack *&s, ElemType e)
{
    if (s->top == MAXSIZE - 1) //上溢
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1) //下溢
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

void printstack(SqStack *s)
{
    while (s->top != -1)
        printf("%d", s->data[s->top--]);
}

bool conversion(int n) //十进制转换为二进制
{
    SqStack *s;
    InitStack(s);
    ElemType e;
    while (n)
    {
        e = n % 2;
        Push(s, e);
        n = n / 2;
    }
    while (!StackEmpty(s))
    {
        Pop(s, e);
        printf("%d", e);
    }
    return true;
}

int main()
{
    // SqStack *s;
    // InitStack(s);
    printf("请输入要转化的数值：");
    int n;
    scanf("%d", &n);
    conversion(n);

    printf("\n");
    return 0;
}
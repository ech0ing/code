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
    SqStack *s2;
    InitStack(s2);
    ElemType e;
    while (n)
    {
        e = n % 2;
        Push(s2, e);
        n = n / 2;
    }
    while (!StackEmpty(s2))
    {
        Pop(s2, e);
        printf("%d", e);
    }
    DestoryStack(s2);
    return true;
}

int main()
{
    SqStack *s;
    InitStack(s);
    ElemType e;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    printf("进栈序列为：");
    for (int n = 0; n < 7; n++)
    {
        printf("%d", arr[n]);
    }
    printf("\n");

    printf("出栈序列为：");
    for (int i = 0; i < 3; i++)
    {
        Push(s, arr[i]);
    }
    Pop(s, e);
    printf("%d", e);
    Push(s, arr[3]);
    Pop(s, e);
    printf("%d", e);
    Pop(s, e);
    printf("%d", e);
    Pop(s, e);
    printf("%d", e);
    for (int j = 4; j < 7; j++)
    {
        Push(s, arr[j]);
    }
    for (int k = 4; k < 7; k++)
    {
        Pop(s, e);
        printf("%d", e);
    }
    printf("\n");

    //进制转换
    printf("请输入要转化的数值：");
    int n;
    scanf("%d", &n);
    conversion(n);
    printf("\n");
    return 0;
}
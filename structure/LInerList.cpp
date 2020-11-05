#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 66

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; //存储空间基址
    int length;             //当前长度
} SqList;

void InitList(SqList *&L) //初始化顺序表
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

void CreateList(SqList *&L, ElemType a[], int n) //建立顺序表
{
    int k = 0, i = 0;
    L = (SqList *)malloc(sizeof(SqList));
    while (i < n)
        L->data[k++] = a[i++];
    L->length = k;
}

void DestroyList(SqList *&L)
{
    free(L);
}

bool ListEmpty(SqList *L)
{
    return (L->length == 0);
}

int ListLength(SqList *L)
{
    return (L->length);
}

void DispList(SqList *L) //输出顺序表
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

bool GetElem(SqList *L, int i, ElemType &e) //查询第i个数的值
{
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1]; //将要找的值赋给e
    return true;
}

int LocateElem(SqList *L, ElemType e) //找出值为e的数的位置
{
    int i = 0;
    while (i < L->length && L->data[i] != e) //查找元素e
        i++;
    if (i >= L->length) //未找到则返回0
        return 0;
    else
        return i + 1; //返回其逻辑序号
}

bool ListInsert(SqList *&L, int i, ElemType e) //按位插入
{
    int j;
    if (i < 1 || i > L->length + 1 || L->length == MAXSIZE) //参数错误则返回false
        return false;
    i--;                            //将逻辑序号化为物理序号
    for (j = L->length; j > i; j--) //将data[i]及后面的元素后移一个位置
        L->data[j] = L->data[j - 1];
    L->data[i] = e; //插入元素e;
    L->length++;    //顺序表长度增1
    return true;
}

void Insert(SqList *L, ElemType x) // 顺序插入
{
    int i = 0, j, k;
    for (k = 0; k < L->length; k++)
    {
        if (L->data[k] < x)
        {
            ++i;
        } //判断选择插入的位置
    }
    for (j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1]; //将i之后的数后移一个位置
    L->data[i] = x;                  //插入x
    L->length++;
}

bool ListDelete(SqList *&L, int i, ElemType &e) //按位置删除,把删除的数存入e
{
    int j;
    if (i < 1 || i > L->length)
        return false;
    i--; //将逻辑序号转化为物理序号
    e = L->data[i];
    for (j = i; j < L->length - 1; j++) //data[i]之后的元素前移一个位置
        L->data[j] = L->data[j + 1];
    L->length--; //顺序表长度-1
    return true;
}

void Del_Same(SqList *&L) //有序顺序表去重
{
    if (L->length == 0)
        printf("the list is illegal"); //表L不合理
    int j = 0;
    for (int i = 1; i < L->length; i++)
    {
        if (L->data[i] != L->data[j])
            L->data[++j] = L->data[i]; //将不相同的元素插入到非重复有序表中
    }
    L->length = j + 1;
}

void swap(ElemType &a, ElemType &b) //交换两个数
{
    ElemType temp;
    temp = a;
    a = b;
    b = temp;
}

void Union(SqList *A, SqList *B, SqList *&C) //两个有序顺序表的并集
{
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length)
    {
        if (A->data[i] < B->data[j]) //按顺序将两个有序顺序表中较小的元素存入表C中
        {
            C->data[k++] = A->data[i++];
        }
        else if (A->data[i] > B->data[j])
        {
            C->data[k++] = B->data[j];
        }
        else
        {
            C->data[k++] = B->data[j++];
            i++;
        }
    }
    while (i < A->length) //将A,B表中较长表的剩余元素接着存入表C中.
        C->data[k++] = A->data[i++];
    while (j < B->length)
        C->data[k++] = B->data[j++];

    C->length = k;
}

void DifferList(SqList *A, SqList *B, SqList *&C) //求A-B差集
{
    int i, j, k = 0;
    for (i = 0; i < A->length; i++)
    {
        j = 0;
        while (j < B->length && B->data[j] != A->data[i])
            j++;
        if (j == B->length) //A中的某个元素在B中没找到则将其放入C中
            C->data[k++] = A->data[i];
    }
    C->length = k;
}

void reverse(SqList *&L) //逆置顺序表
{
    int i;
    for (i = 0; i < L->length / 2; i++)
    {
        swap(L->data[i], L->data[L->length - i - 1]);
    }
}

void movelist(SqList *&L) //排序,奇数在左,偶数在右
{
    int i = 0, j = L->length - 1;
    while (i < j)
    {
        while (i < j && L->data[j] % 2 == 0)
            j--; //从右向左扫描,找出奇数元素
        while (i < j && L->data[i] % 2 == 1)
            i++; //从左向右扫描,找出偶数元素
        if (i < j)
            swap(L->data[i], L->data[j]);
    }
}

void SortList(SqList *&L, int k1, int k2) //先后以k1,k2为基准进行排列
{
    int i = 0, j = L->length - 1;
    while (i < j)
    {
        while (i < j && L->data[j] > k1) //从后往前,找到小于k1的值
            j--;
        while (i < j && L->data[i] < k1) //从前往后,找到大于k1的值
            i++;
        swap(L->data[i], L->data[j]); //交换找到的两值
    }
    int x = 0, y = L->length - 1;
    while (x < y)
    {
        while (x < y && L->data[y] > k2)
            y--;
        while (x < y && L->data[x] < k2)
            x++;
        swap(L->data[x], L->data[y]);
    }
}

int main()
{
    SqList *L;
    SqList *A, *B, *C;
    //实验一
    printf("实验一:\n");
    InitList(L);
    int a[] = {3, 2, 4, 5};
    CreateList(L, a, 4);
    DispList(L);
    if (ListInsert(L, 4, 9)) //插入
    {
        printf("插入成功:");
        DispList(L);
    }
    else
        printf("插入失败");

    int e;
    if (ListDelete(L, 3, e)) //删除
    {
        printf("删除成功:");
        DispList(L);
    }
    else
        printf("删除失败");
    DestroyList(L);
    printf("\n");

    //实验二
    printf("实验二:\n");
    InitList(L);
    int b[] = {6, 4, 10, 7, 9, 2, 20, 1, 3, 30};
    CreateList(L, b, 10);
    printf("Before:");
    DispList(L);
    int k1, k2;
    printf("请输入两个边界值,两个值用空格隔开:");
    scanf("%d %d", &k1, &k2);
    SortList(L, k1, k2);
    printf("After:");
    DispList(L);
    DestroyList(L);
    printf("\n");

    //实验三
    printf("实验三:\n");
    InitList(A); //求A-B差集
    int A_data[] = {1, 3, 4, 5, 6, 7};
    InitList(B);
    int B_data[] = {3, 5, 6, 8, 9, 11};
    InitList(C);
    CreateList(A, A_data, 6);
    CreateList(B, B_data, 6);
    printf("A:");
    DispList(A);
    printf("B:");
    DispList(B);
    DifferList(A, B, C);
    printf("差集C:");
    DispList(C);
    DestroyList(A);
    DestroyList(B);
    DestroyList(C);
    printf("\n");
    return 0;
}
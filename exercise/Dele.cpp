#include <stdio.h>
#include <malloc.h>
#define LIST_INIT_SIZE 100
#define true 1
#define false 0
typedef int ElemType;
typedef struct
{
	ElemType *elem; //存储空间基址
	int length;		//当前长度
} SqList;
void InitList(SqList *l)
{ //初始化顺序表
	l->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	l->length = 0;
}
void CreateList(SqList *l)
{ //创建顺序表
	int data, i = 0;
	scanf("%d", &data);
	while (!(data < 0))
	{
		l->elem[i++] = data;
		l->length++;
		scanf("%d", &data);
	}
}
void print(SqList list)
{ //打印顺序表
	int i = 0;
	while (i < list.length)
	{
		printf("%d ", list.elem[i++]);
	}
	printf("\n");
}
/* void distinc(SqList *l)
{ //去除重复元素
	int *p, *q, *r = l->length + l->elem;
	for (p = l->elem, q = p + 1; q < r; q++)
	{
		if (*p != *q)
		{
			*(p + 1) = *q;
			p++;
		}
		else
		{
			l->length--;
		}
	}
} */
/* void ListDel(SqList *l)
{
	int  i,  j=1,  len = 1;
	while (i < l->length)
	{
		for (i = 0; i < len; i++)
		{
			if (l->elem[i] == l->elem[j])
				break;
		}
		if (i == len)
			l->elem[len++] = l->elem[j++];
		else  
			j++;
	}
	l->length = len;
} */

void Del_Same(SqList *L)
{
	//删除有序顺序表中值重复的元素
	if (L->length == 0)
		printf("error"); //表L不合理
	int j = 0;
	for (int i = 1; i < L->length; i++)
	{
		if (L->elem[i] != L->elem[j])
			L->elem[++j] = L->elem[i]; //将不相同的元素插入到非重复有序表中
	}
	L->length = j + 1;
}

void Insert(SqList *L, ElemType x)
// 在有序的顺序表 L 中按序插入数据元素 x
{
	int i = 0, j, k;
	for (k = 0; k < L->length; k++)
	{
		if (L->elem[k] < x)
		{
			++i;
		} //判断选择插入的位置
	}
	for (j = L->length; j > i; j--)
		L->elem[j] = L->elem[j - 1]; //将i之后的数后移一个位置
	L->elem[i] = x;					 //插入x
	L->length++;
}
void swap(ElemType *a, ElemType *b)
{ //交换两个数
	ElemType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//将两个顺序表按顺序连接起来
void Union(SqList *A, SqList *B, SqList *&C)
{
	int i=0, j=0, k=0;
	while (i < A->length && j < B->length)
	{
		//按顺序将两个有序顺序表中较小的元素存入表C中
		if (A->elem[i] < B->elem[j])
		{
			C->elem[k++] = A->elem[i++];
		}
		else if (A->elem[i]>B->elem[j])
		{
			C->elem[k++] = B->elem[j];
		}
		else
		{
			C->elem[k++] = B->elem[j++];
			i++;
		}
	}
	//将A,B表中较长表的剩余元素接着存入表C中.
	while(i<A->length) 
    C->elem[k++]=A->elem[i++];
    while(j<B->length) 
    C->elem[k++]=B->elem[j++];

    C->length=k;
}

void reverse(SqList l)
{ //逆置顺序表
	int i;
	for (i = 0; i < l.length / 2; i++)
	{
		swap(l.elem + i, l.elem + l.length - 1 - i);
	}
}

void movelist(SqList L)
{
	int i = 0, j = L.length - 1;
	while (i < j)
	{
		while (i < j && L.elem[j] % 2 == 0)
			j--; //从右向左扫描,找出奇数元素
		while (i < j && L.elem[i] % 2 == 1)
			i++; //从左向右扫描,找出偶数元素
		if (i < j)
			swap(L.elem + i, L.elem + j);
	}
}

int main()
{
	while (1)
	{
		SqList L;
		InitList(&L);
		printf("输入正整数，负数代表结束哦：\n");
		CreateList(&L);
		/* printf("去除重复元素：");
		distinc(&L);
		Del_Same(&L); */
		print(L);
		/* printf("输入要插入的整数：\n");
		ElemType x;
		scanf("%d", &x);
		Insert(&L, x); */
		movelist(L);
		//reverse(L);
		// printf("反转：");
		//printf("插入之后的线性表：\n");
		print(L);
	}
	return 0;
}
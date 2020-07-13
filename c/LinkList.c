//链表的创建和操作
#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *List;

List InitList();//带头结点的链表的建立
int Listlength(List L);//求链表的长度
void ListInsert(List L, int i, ElemType e);//在L中第i个位置之后插入一个结点的数值为e
void ListDelete(List L, int i);//链表第i个结点的删除
int GetElemtype(List L, int i);// 返回L中第i个位置的数据元素的值
void GetElem(List L, ElemType e);//查找在链表中是否有e这个元素，有的话返回它在链表中的位置，没有的话显示无
void ListCleaner(List L);//链表的清除
void print(List L);//链表的输出

List InitList()//带头结点的链表的建立（需要参数和不需要参数同理）
{
	Node *last;//p为插入结点，last始终指向末节点;
	List L;
	L = (Node *)malloc(sizeof(Node));
	L->next == NULL;
	last = L;
	ElemType elem;
	printf("已为您创建链表，请输入每个元素的值（以空格隔开并且以-1为结尾且不计入链表之中）\n");
	while (scanf("%d", &elem) && elem != -1)
	{
		Node *p;
		p = (Node *)malloc(sizeof(Node));
		p->data = elem;
		last->next = p;
		last = p;
	}
	last->next = NULL;
	printf("链表以创建成功！\n");
	return L;
}
int Listlength(L)//求链表的长度
{
	Node *p;
	p = L;
	int temp = 0;
	while (p->next != NULL)
	{
		temp++;
		p = p->next;
	}
	return temp;
}
void ListInsert(List L, int i, ElemType e)//在L中第i个位置之后插入一个结点的数值为e
{
	int j = 0;
	Node *p, *temp;
	p = L;
	while (j<i)
	{
		p = p->next;
		j++;
	}
	temp = (Node *)malloc(sizeof(Node));//新建一个结点
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
}
void print(List L)//链表的输出
{
	List tempList;
	tempList = L->next;
	while (tempList)
	{
		printf("%d ", tempList->data);
		tempList = tempList->next;
	}
}
void ListDelete(List L, int i)//链表第i个结点的删除
{
	if (i<1 || i>Listlength(L) + 1)
	{
		exit(0);
	}
	int j = 0;
	Node *p;
	p = L;
	while (p&&j < i - 1)//找到第i个位置前的结点
	{
		p = p->next;
		j++;
	}
	p->next = p->next->next;
}
int GetElemtype(List L, int Position)// 返回L中第i个数据元素的值
{
	Node *p;
	p = L;
	for (int j = 0; j < Position; j++)
	{
		p = p->next;
	}
	return p->data;
}

void ListCleaner(List L)//链表的清除
{
	List p = NULL, q = NULL;//让p指向当前要删除的结点，q指向p之后的结点，等p释放空间后再重复上述操作
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	printf("链表已经清除！\n");
}
void GetElem(List L, ElemType e)//查找在链表中是否有e这个元素，有的话返回它在链表中的位置
{
	Node *p;
	int temp = 0;
	p = L->next;
	while (p)
	{
		temp++;
		if (p->data == e)
		{
			printf("结果：该元素在第%d个位置\n", temp);
			exit(0);
		}
		p = p->next;
	}
	printf("结果：未找到相关元素！\n");
}


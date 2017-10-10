#include <iostream>
#include <time.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

/* 
int  InitList(LinkList *L)                    //初始化操作
void InitListWithHead(LinkList L)             //初始化操作，带头节点
void CreateListHead(LinkList *L, int n)       //头插法
void CreateListTail(LinkList *L, int n)       //尾插法
int GetLinkListLength(LinkList L)             //返回链表长度
int ClearList(LinkList *L)                    //整表删除
int GetElem(LinkList L, int i, int *e)        //将链表L中第i个元素返回给e
int LocateElem(LinkList L, int e)             //将链表L中值为e的元素位置返回
int ListInsert(LinkList *L, int i, int e)     //在链表L中第i个结点插入新的数据元素
int ListDelete(LinkList *L, int i, int *e)    //删除链表L中第i个元素
int ListEmpty(LinkList L)                     //判断是否为空
int output(LinkList L)                        //输出链表
*/

int InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if (!(*L)) /* 存储分配失败 */
		return ERROR;
	(*L)->next = NULL; /* 指针域为空 */
	cout << "初始化成功！" << endl;
	return OK;
}

void  ListEmpty(LinkList L)//判断是否为空
{
	if (L->next)
		cout << "链表非空！" << endl;
	else
		cout << "链表为空！" << endl;
}

void CreateListHead(LinkList *L, int n)//头插法
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 1; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList *L, int n)//尾插法
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int GetLinkListLength(LinkList L) //返回链表长度
{
	int length=0;
	LinkList s;
	s = L->next;
	while (s)
	{
		length++;
		s = s->next;
	}
	return length;
}

int ClearList(LinkList *L)//整表删除
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
		return OK;
}

int GetElem(LinkList L, int i, int *e)//将链表L中第i个元素返回给e
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

int LocateElem(LinkList L, int e)//将链表L中值为e的元素位置返回
{
	LinkList p;
	int count=0;
	p = L->next;
	while (p!=NULL&&(p->data!=e))
	{
		p = p->next;
		count++;
	}
	return count;
}

int ListInsert(LinkList *L, int i, int e)//在链表L中第i个结点插入新的数据元素
{
	int pos = 1;
	LinkList p, s;
	p = *L;
	while (p&&pos < i)
	{
		p = p->next;
		pos++;
	}
	if (!p || pos > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

int ListDelete(LinkList *L, int i, int *e)//删除链表L中第i个元素
{
	int pos = 1;
	LinkList p, s;
	p = *L;
	while (p->next&&pos < i)
	{
		p = p->next;
		pos++;
	}
	if (!(p->next) || pos > i)
		return ERROR;
	s = p->next;
	p->next = s->next;
	*e = s->data;
	free(s);
	s->next = NULL;
	return OK;
}

int output(LinkList L)//输出链表
{
	LinkList p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return OK;
}

int main()
{

	LinkList L;
	int e;
	int i;
	int Len;
	int find_E, find_L;
	int insert_L, insert_E;
	int delete_L;

	i = InitList(&L);
	Len = GetLinkListLength(L);
	cout<<"链表长度为"<<Len<<"\n\n";

	cout << "1.头插法建立链表" << endl;
	cout << "2.尾插法建立链表" << endl;
	cout << "3.返回第i个元素的值" << endl;
	cout << "4.返回值为i的元素位置" << endl;
	cout << "5.插入元素" << endl;
	cout << "6.删除元素" << endl;
	cout << "7.清空" << endl;

	int switch_on = 99;
	while (switch_on != 0)
	{
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			CreateListHead(&L, 20);
			output(L);
			break;
		case 2:
			CreateListTail(&L, 20);
			output(L);
			break;
		case 3:
			GetElem(L, 5, &e);
			cout << "第五个元素的值：" << e << endl;
			break;
		case 4:
			
			cout << "输入要查找的元素：";
			cin >> find_E;
			find_L = LocateElem(L, find_E);
			cout << "元素" << find_E << "的位置是：" << find_L + 1 << endl;
			break;
		case 5:
			cout << "输入插入位置：";
			cin >> insert_L;
			cout << "输入插入元素：";
			cin >> insert_E;
			ListInsert(&L, insert_L, insert_E);
			output(L);
			break;
		case 6:
			cout << "输入删除位置：";
			cin >> delete_L;
			ListDelete(&L, insert_L,&e);
			output(L);
			break;
		case 7:
			i = ClearList(&L);
			printf("清空L后：ListLength(L)=%d\n", GetLinkListLength(L));
			ListEmpty(L);
			break;
		case 0:
			exit(0);
		}
	}
}
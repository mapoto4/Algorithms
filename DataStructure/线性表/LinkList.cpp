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
int  InitList(LinkList *L)                    //��ʼ������
void InitListWithHead(LinkList L)             //��ʼ����������ͷ�ڵ�
void CreateListHead(LinkList *L, int n)       //ͷ�巨
void CreateListTail(LinkList *L, int n)       //β�巨
int GetLinkListLength(LinkList L)             //����������
int ClearList(LinkList *L)                    //����ɾ��
int GetElem(LinkList L, int i, int *e)        //������L�е�i��Ԫ�ط��ظ�e
int LocateElem(LinkList L, int e)             //������L��ֵΪe��Ԫ��λ�÷���
int ListInsert(LinkList *L, int i, int e)     //������L�е�i���������µ�����Ԫ��
int ListDelete(LinkList *L, int i, int *e)    //ɾ������L�е�i��Ԫ��
int ListEmpty(LinkList L)                     //�ж��Ƿ�Ϊ��
int output(LinkList L)                        //�������
*/

int InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!(*L)) /* �洢����ʧ�� */
		return ERROR;
	(*L)->next = NULL; /* ָ����Ϊ�� */
	cout << "��ʼ���ɹ���" << endl;
	return OK;
}

void  ListEmpty(LinkList L)//�ж��Ƿ�Ϊ��
{
	if (L->next)
		cout << "����ǿգ�" << endl;
	else
		cout << "����Ϊ�գ�" << endl;
}

void CreateListHead(LinkList *L, int n)//ͷ�巨
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

void CreateListTail(LinkList *L, int n)//β�巨
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

int GetLinkListLength(LinkList L) //����������
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

int ClearList(LinkList *L)//����ɾ��
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

int GetElem(LinkList L, int i, int *e)//������L�е�i��Ԫ�ط��ظ�e
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

int LocateElem(LinkList L, int e)//������L��ֵΪe��Ԫ��λ�÷���
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

int ListInsert(LinkList *L, int i, int e)//������L�е�i���������µ�����Ԫ��
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

int ListDelete(LinkList *L, int i, int *e)//ɾ������L�е�i��Ԫ��
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

int output(LinkList L)//�������
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
	cout<<"������Ϊ"<<Len<<"\n\n";

	cout << "1.ͷ�巨��������" << endl;
	cout << "2.β�巨��������" << endl;
	cout << "3.���ص�i��Ԫ�ص�ֵ" << endl;
	cout << "4.����ֵΪi��Ԫ��λ��" << endl;
	cout << "5.����Ԫ��" << endl;
	cout << "6.ɾ��Ԫ��" << endl;
	cout << "7.���" << endl;

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
			cout << "�����Ԫ�ص�ֵ��" << e << endl;
			break;
		case 4:
			
			cout << "����Ҫ���ҵ�Ԫ�أ�";
			cin >> find_E;
			find_L = LocateElem(L, find_E);
			cout << "Ԫ��" << find_E << "��λ���ǣ�" << find_L + 1 << endl;
			break;
		case 5:
			cout << "�������λ�ã�";
			cin >> insert_L;
			cout << "�������Ԫ�أ�";
			cin >> insert_E;
			ListInsert(&L, insert_L, insert_E);
			output(L);
			break;
		case 6:
			cout << "����ɾ��λ�ã�";
			cin >> delete_L;
			ListDelete(&L, insert_L,&e);
			output(L);
			break;
		case 7:
			i = ClearList(&L);
			printf("���L��ListLength(L)=%d\n", GetLinkListLength(L));
			ListEmpty(L);
			break;
		case 0:
			exit(0);
		}
	}
}
/**
* Created by mapo on 2017/07/03.
*/
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef struct
{
	int data[MAXSIZE];
	int top;
}SqStack;

/*
int InitStack(SqStack *s)       ��ʼ��ջ
int ClearStack(SqStack *s)      ���ջ
int StackEmpty(SqStack s)       �ж�ջ�Ƿ�Ϊ��
int StackLength(SqStack s)      ����ջ�ĳ���
int GetTop(SqStack s, int *e)   ����ջ��Ԫ��
int Push(SqStack *s, int e)     ����Ԫ��eΪ��ջ��Ԫ��
int Pop(SqStack *s, int e)      �ж�ջ�Ƿ�Ϊ�գ����ǿ���ɾ��ջ��Ԫ��
void print(SqStack s)			��ӡջ
*/


int InitStack(SqStack *s)
{
	s->top = -1;
	return OK;
}

int ClearStack(SqStack *s)
{
	s->top = -1;
	return OK;
}

int StackEmpty(SqStack s)
{
	if (s.top == -1)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack s)
{
	return s.top + 1;
}

int GetTop(SqStack s, int *e)
{
	if (s.top == -1)
		return ERROR;
	else
		*e = s.data[s.top];
	return OK;
}

int Push(SqStack *s, int e)
{
	if (s->top == MAXSIZE - 1)
		return ERROR;
	else
		s->top++;
	s->data[s->top] = e;
	return OK;
}

int Pop(SqStack *s, int &e)
{
	if (s->top == -1)
		return ERROR;
	else
		e = s->data[s->top];
	s->top--;
	return OK;
}

void print(SqStack s)
{
	

	int i=0;
	while (i <= s.top)
	{
		cout<<s.data[i++]<<" ";
	}
	cout<<endl;
}

void main()
{
	SqStack s;
	int j;
	int e=0 ;
	int f=0;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			Push(&s, j);

	cout << "1.��ʾջ��Ԫ��"<<endl;
	cout << "2.����ջ��Ԫ��" << endl;
	cout << "3.����ջ�ĳ���" << endl;
	cout << "4.�ж�ջ�Ƿ�Ϊ��" << endl;
	cout << "5.���ջ" << endl;
	cout << "6.ѹջ" << endl;
	cout << "7.��ջ" << endl;

	int switch_on = 1;
	while (switch_on!=0)
	{
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			print(s);
			break;
		case 2:
			GetTop(s, &e);
			cout << "ջ��Ԫ��" << e << endl;
			break;
		case 3:
			cout << "ջ�ĳ���Ϊ" << StackLength(s) << endl;
			break;
		case 4:
			cout << "ջ�շ� 1:�� 0:��   �� " << StackEmpty(s) << endl;
			break;
		case 5:
			ClearStack(&s);
			cout << "�����ɣ�";
			break;
		case 6:
			int input;
			cout << "����ѹ�����ֵ��";
			cin >> input;
			Push(&s, input);
			cout << "��ɲ�����"<<endl;
			break;
		case 7:
			Pop(&s, f);
			cout << "������ջ��Ԫ��" << f << endl;
			break;
		case 0:
			break;
		}
	}
}
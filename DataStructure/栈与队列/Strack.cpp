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
int InitStack(SqStack *s)       初始化栈
int ClearStack(SqStack *s)      清空栈
int StackEmpty(SqStack s)       判断栈是否为空
int StackLength(SqStack s)      返回栈的长度
int GetTop(SqStack s, int *e)   返回栈顶元素
int Push(SqStack *s, int e)     插入元素e为新栈顶元素
int Pop(SqStack *s, int e)      判断栈是否为空，若非空则删除栈顶元素
void print(SqStack s)			打印栈
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

	cout << "1.显示栈中元素"<<endl;
	cout << "2.返回栈顶元素" << endl;
	cout << "3.返回栈的长度" << endl;
	cout << "4.判断栈是否为空" << endl;
	cout << "5.清空栈" << endl;
	cout << "6.压栈" << endl;
	cout << "7.出栈" << endl;

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
			cout << "栈顶元素" << e << endl;
			break;
		case 3:
			cout << "栈的长度为" << StackLength(s) << endl;
			break;
		case 4:
			cout << "栈空否 1:空 0:否   ： " << StackEmpty(s) << endl;
			break;
		case 5:
			ClearStack(&s);
			cout << "清空完成！";
			break;
		case 6:
			int input;
			cout << "输入压入的数值：";
			cin >> input;
			Push(&s, input);
			cout << "完成操作！"<<endl;
			break;
		case 7:
			Pop(&s, f);
			cout << "弹出的栈顶元素" << f << endl;
			break;
		case 0:
			break;
		}
	}
}
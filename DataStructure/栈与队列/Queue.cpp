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
	int front;    
	int rear;		
}SqQueue;

int InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return  OK;
}

int ClearQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	return OK;
}

int QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear) 
		return TRUE;
	else
		return FALSE;
}

int QueueLength(SqQueue Q)
{
	return  (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int GetHead(SqQueue Q, int *e)
{
	if (Q.front == Q.rear) /* ���п� */
		return ERROR;
	*e = Q.data[Q.front];
	return OK;
}

int EnQueue(SqQueue *Q, int e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q->data[Q->rear] = e;			/* ��Ԫ��e��ֵ����β */
	Q->rear = (Q->rear + 1) % MAXSIZE;/* rearָ�������һλ�ã����������ת������ͷ�� */
	return  OK;
}

int DeQueue(SqQueue *Q, int *e)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e = Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front = (Q->front + 1) % MAXSIZE;	/* frontָ�������һλ�ã����������ת������ͷ�� */
	return  OK;
}

int print(SqQueue Q)
{
	int i;
	i = Q.front;
	while ((i + Q.front) != Q.rear)
	{
		cout<<Q.data[i]<<" ";
		i = (i + 1) % MAXSIZE;
	}
	cout<<endl;
	return OK;
}

void main()
{
	int i = 0;
	int d;
	SqQueue Q;
	InitQueue(&Q);

	do
	{
		d = i + 100;
		if (d == -1)
			break;
		i++;
		EnQueue(&Q, d);
	} while (i<MAXSIZE - 1);
	
	cout << "1.��ʼ������" << endl;
	cout << "2.��ʾ������Ԫ��" << endl;
	cout << "3.���ض���ͷԪ��" << endl;
	cout << "4.���ض��еĳ���" << endl;
	cout << "5.�ж϶����Ƿ�Ϊ�գ�1���ǿ�  0���գ�" << endl;
	cout << "6.��ն���" << endl;
	cout << "7.���" << endl;
	cout << "8.����" << endl;

	int switch_on = 1;
	while (switch_on != 0)
	{
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			InitQueue(&Q);
			cout << "��ʼ����ɣ�"<<endl;
			break;
		case 2:
			print(Q);
			break;
		case 3:
			int e;
			GetHead(Q, &e);
			cout << "����Ԫ���ǣ�" << e << endl;
			break;
		case 4:
			cout<<"���г��ȣ�"<<QueueLength(Q)<<endl;
			break;
		case 5:
			cout << QueueEmpty(Q);
			break;
		case 6:
			ClearQueue(&Q);
			cout << "�����ϣ�" << endl;
			break;
		case 7:
			int ele;
			cout << "���������ֵ��";
			cin >> ele;
			EnQueue(&Q, ele);
			cout << "��ӳɹ���"<<endl;
			break;
		case 8:
			int t;
			DeQueue(&Q, &t);
			cout << "���ӳɹ���" << endl;
		case 0:
			break;
		}
	}
}


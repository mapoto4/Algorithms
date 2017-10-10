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
	if (Q.front == Q.rear) /* 队列空 */
		return ERROR;
	*e = Q.data[Q.front];
	return OK;
}

int EnQueue(SqQueue *Q, int e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)	/* 队列满的判断 */
		return ERROR;
	Q->data[Q->rear] = e;			/* 将元素e赋值给队尾 */
	Q->rear = (Q->rear + 1) % MAXSIZE;/* rear指针向后移一位置，若到最后则转到数组头部 */
	return  OK;
}

int DeQueue(SqQueue *Q, int *e)
{
	if (Q->front == Q->rear)			/* 队列空的判断 */
		return ERROR;
	*e = Q->data[Q->front];				/* 将队头元素赋值给e */
	Q->front = (Q->front + 1) % MAXSIZE;	/* front指针向后移一位置，若到最后则转到数组头部 */
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
	
	cout << "1.初始化队列" << endl;
	cout << "2.显示队列中元素" << endl;
	cout << "3.返回队列头元素" << endl;
	cout << "4.返回队列的长度" << endl;
	cout << "5.判断队列是否为空（1：非空  0：空）" << endl;
	cout << "6.清空队列" << endl;
	cout << "7.入队" << endl;
	cout << "8.出队" << endl;

	int switch_on = 1;
	while (switch_on != 0)
	{
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			InitQueue(&Q);
			cout << "初始化完成！"<<endl;
			break;
		case 2:
			print(Q);
			break;
		case 3:
			int e;
			GetHead(Q, &e);
			cout << "队首元素是：" << e << endl;
			break;
		case 4:
			cout<<"队列长度："<<QueueLength(Q)<<endl;
			break;
		case 5:
			cout << QueueEmpty(Q);
			break;
		case 6:
			ClearQueue(&Q);
			cout << "清空完毕！" << endl;
			break;
		case 7:
			int ele;
			cout << "输入入队数值：";
			cin >> ele;
			EnQueue(&Q, ele);
			cout << "入队成功！"<<endl;
			break;
		case 8:
			int t;
			DeQueue(&Q, &t);
			cout << "出队成功！" << endl;
		case 0:
			break;
		}
	}
}


#include <iostream>
using namespace std;

#define MAXSIZE 20

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct
{
	int data[MAXSIZE];
	int length;
}Sqlist;

void InitList(Sqlist &L)//建立空线性表L
{
	L.length = 0;
}

int ListEmpty(Sqlist L)//判断线性表是否为空
{
	if (L.length == 0)
		return TRUE;
	else 
		return FALSE;
}

int ListLength(Sqlist L)//返回线性表L的元素个数
{
	return L.length;
}

int LocateElem(Sqlist L, int x)//查找线性表L中值为x返回位置
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (x == L.data[i])
		{
			return i+1;
		}
	}
	return FALSE;
}

int GetElem(Sqlist L, int p, int &e)//用e返回线性表L中位置p的值
{
	if (L.length==0||p < 1 || p>L.length)
		return ERROR;
	e = L.data[p-1];
	return OK;
}

int ListInsert(Sqlist &L, int p, int e)//在线性表L中第p位置插入e
{
	int i;
	if (p<1 || p>L.length + 1 || L.length == MAXSIZE - 1)
		return ERROR;
	for (i = L.length; i >=p-1; i--)
		L.data[i + 1] = L.data[i];
	L.data[p-1] = e;
	L.length++;
	return OK;
}

int ListDelete(Sqlist &L, int p, int &e)//删除线性表L中第p个位置元素，并用e返回其值
{
	int i;
	if (p<1 || p>L.length)
		return ERROR;
	e = L.data[p];
	for (i = p-1; i < L.length; i++)
		L.data[i] = L.data[i + 1];
	L.length--;
	return OK;
}

int main()
{
	Sqlist list = {
		{1,2,3,4,5,6,7},
		7
	};
	int x;
	int locate;

	int search_p;
	int e;

	int insert_p;
	int value;

	int delete_p;
	int result;

	int empty;

	cout<<" \n1.遍历表中元素\n2.按元素查找表中位置 \n3.按位置查找表中元素 \n4.插入元素\n5.删除元素 \n6.线性表是否为空\n0.退出 \n请选择你的操作：\n";

	int switch_on=1;
	while (switch_on !=0)
	{
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			cout << "遍历线性表结果：";
			for (int i = 0; i < list.length; i++)
			{
				cout << list.data[i] << " ";
			}
			cout << endl;
			break;
		case 2:
			cout << "输入要查找的元素：";
			cin >> x;
			locate = LocateElem(list, x);
			if (locate)
				cout << "元素为" << x << "是表中第" << locate << "个元素" << endl;
			else
				cout << "没有找到索要查找的值" << endl;
			break;
		case 3:
			cout << "输入要查找的位置：";
			cin >> search_p;
			GetElem(list, search_p, e);
			cout << "第" << search_p << "个位置的元素是" << e << endl;
			break;
		case 4:
			cout<<"请输入插入元素位置：";
			cin >> insert_p;
			cout<<"请输入插入元素的值：";
			cin>>value;
		    ListInsert(list, insert_p, value);
			cout<<"插入完毕，现在线性表为：";
			for (int i = 0; i < list.length; i++)
			{
				cout << list.data[i] << " ";
			}
			cout << "线性表长度为：" << list.length << endl;
			break;
		case 5:
			cout << "请输入删除元素位置：";
			cin >> delete_p;
			ListDelete(list, delete_p, result);
			cout << "删除完毕，现在线性表为：";
			for (int i = 0; i < list.length; i++)
			{
				cout << list.data[i] << " ";
			}
			cout <<"线性表长度为："<<list.length<< endl;
			break;
		case 6:
			empty = ListEmpty(list);
			if (empty)
				cout << "该线性表为空.\n";
			else
				cout << "该线性表非空\n";
			break;

		case 0:
			exit(0);
		}

	}
}


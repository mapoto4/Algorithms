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

void InitList(Sqlist &L)//���������Ա�L
{
	L.length = 0;
}

int ListEmpty(Sqlist L)//�ж����Ա��Ƿ�Ϊ��
{
	if (L.length == 0)
		return TRUE;
	else 
		return FALSE;
}

int ListLength(Sqlist L)//�������Ա�L��Ԫ�ظ���
{
	return L.length;
}

int LocateElem(Sqlist L, int x)//�������Ա�L��ֵΪx����λ��
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

int GetElem(Sqlist L, int p, int &e)//��e�������Ա�L��λ��p��ֵ
{
	if (L.length==0||p < 1 || p>L.length)
		return ERROR;
	e = L.data[p-1];
	return OK;
}

int ListInsert(Sqlist &L, int p, int e)//�����Ա�L�е�pλ�ò���e
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

int ListDelete(Sqlist &L, int p, int &e)//ɾ�����Ա�L�е�p��λ��Ԫ�أ�����e������ֵ
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

	cout<<" \n1.��������Ԫ��\n2.��Ԫ�ز��ұ���λ�� \n3.��λ�ò��ұ���Ԫ�� \n4.����Ԫ��\n5.ɾ��Ԫ�� \n6.���Ա��Ƿ�Ϊ��\n0.�˳� \n��ѡ����Ĳ�����\n";

	int switch_on=1;
	while (switch_on !=0)
	{
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			cout << "�������Ա�����";
			for (int i = 0; i < list.length; i++)
			{
				cout << list.data[i] << " ";
			}
			cout << endl;
			break;
		case 2:
			cout << "����Ҫ���ҵ�Ԫ�أ�";
			cin >> x;
			locate = LocateElem(list, x);
			if (locate)
				cout << "Ԫ��Ϊ" << x << "�Ǳ��е�" << locate << "��Ԫ��" << endl;
			else
				cout << "û���ҵ���Ҫ���ҵ�ֵ" << endl;
			break;
		case 3:
			cout << "����Ҫ���ҵ�λ�ã�";
			cin >> search_p;
			GetElem(list, search_p, e);
			cout << "��" << search_p << "��λ�õ�Ԫ����" << e << endl;
			break;
		case 4:
			cout<<"���������Ԫ��λ�ã�";
			cin >> insert_p;
			cout<<"���������Ԫ�ص�ֵ��";
			cin>>value;
		    ListInsert(list, insert_p, value);
			cout<<"������ϣ��������Ա�Ϊ��";
			for (int i = 0; i < list.length; i++)
			{
				cout << list.data[i] << " ";
			}
			cout << "���Ա���Ϊ��" << list.length << endl;
			break;
		case 5:
			cout << "������ɾ��Ԫ��λ�ã�";
			cin >> delete_p;
			ListDelete(list, delete_p, result);
			cout << "ɾ����ϣ��������Ա�Ϊ��";
			for (int i = 0; i < list.length; i++)
			{
				cout << list.data[i] << " ";
			}
			cout <<"���Ա���Ϊ��"<<list.length<< endl;
			break;
		case 6:
			empty = ListEmpty(list);
			if (empty)
				cout << "�����Ա�Ϊ��.\n";
			else
				cout << "�����Ա�ǿ�\n";
			break;

		case 0:
			exit(0);
		}

	}
}


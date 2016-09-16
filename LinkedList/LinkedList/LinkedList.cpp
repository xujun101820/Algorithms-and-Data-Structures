// LinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#define ERROR 0
#define OK 1;
using namespace std;
struct Node
{
	int value;
	Node *next;
};
void addToTail(Node **head,int value)
{
	Node *pNew = new Node(); Node *p = *head;
	pNew->value = value; pNew->next = NULL;
	if (*head == NULL)
		*head = pNew;
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pNew;
	}
}
int getSize(Node **head)
{
	if (*head == NULL || head == NULL) return 0;
	int i = 1; Node *p = *head;
	while (p->next!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
int insertAnyPos(Node **head,int pos, int value)
{
	Node *pNew = new Node(); Node *p = *head;
	pNew->value = value; pNew->next = NULL;
	int size = getSize(head);
	if (pos<1 || pos>size + 1) return ERROR;
	if (pos == 1)
	{
		pNew->next = *head;
		*head = pNew;
	}
	if (pos == size + 1)
	{
		addToTail(head, value);
	}
	if (pos > 1 && pos < size + 1)
	{
		int count = 2;
		while (count != pos)
		{
			p = p->next;
			count++;
		}
		pNew->next= p->next;
		p->next = pNew;
	}
	return OK;
}
int removeAnyPos(Node **head, int pos, int *value)
{
	Node *p = *head;
	int size = getSize(head);
	if (pos<1 || pos>size||size==0) return ERROR;
	if (pos == 1)
	{
		*head = (*head)->next;
		delete(p);
	}
	if (pos > 1 && pos <=size)
	{
		int count = 2;
		while (count != pos)
		{
			p = p->next;
			count++;
		}
		Node *temp = p->next;
		p->next=p->next->next;
		delete temp;
	}
	return OK;
}
Node * create(int n)
{
	if (n <= 0) return NULL;
	Node *head = new Node(); Node *p = head;
	for (int i = 0; i < n; i++)
	{
		cout << "总共要插入：" << n << "个元素" << endl;
		cout << "输入第" << i + 1 << "个元素" << endl;
		int temp;
		cin >> temp;
		Node *TEM = new Node();
		TEM->value = temp; TEM->next = NULL;
		p->next = TEM; p = p->next;
	}
	return head;
}
//int * pp()
//{
//	int a = 4;
//	
//	return &a;
//}
//void test()
//{
//	int i = 0;
//}
void printListReverse(Node *head)
{
	stack<int> temp;
	Node *p = head;
	while (p != NULL)
	{
		temp.push(p->value);
		p = p->next;
	}
	while (!temp.empty())
	{
		cout << temp.top()<< endl;
		temp.pop();
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	Node *L1 = NULL;
	addToTail(&L1, 5); addToTail(&L1,6); addToTail(&L1, 7);
	insertAnyPos(&L1,4,9);
	printListReverse(L1);
	int out;
	removeAnyPos(&L1, 1,&out);
	cout << "" << endl;
	return 0;
}


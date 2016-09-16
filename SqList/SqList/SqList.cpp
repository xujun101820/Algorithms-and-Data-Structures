// SqList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define ERROR 0
#define OK 1
const int MAXSIZE = 20;
struct SqList
{
	int data[MAXSIZE];
	int length;
};
int getElem(SqList L,int i,int *out)
{
	if (L.length == 0 || i > L.length || i < 1)return ERROR;
	*out = L.data[i - 1];
	return OK;

}
int tailAdd(SqList *L, int i)
{
	if ((*L).length == MAXSIZE) return ERROR;
	(*L).data[(*L).length++] = i;
	return OK;
}
int insertAnyPos(SqList *L,int pos,int i)
{
	if ((*L).length == MAXSIZE) return ERROR;
	if (pos<1 || pos>((*L).length + 1)) return ERROR;
	if (pos <= (*L).length)
	{
		for (int j = (*L).length - 1; j >=pos-1 ; j--)
			(*L).data[j + 1] = (*L).data[j];
	}
	(*L).data[pos-1] = i;
	(*L).length++;
	return OK;
}
int deleteElem(SqList *L, int pos, int *out)
{
	if ((*L).length == 0) return ERROR;
	if (pos<1 || pos>(*L).length) return ERROR;
	*out = (*L).data[pos - 1];
	for (int j = pos-1; j <L->length-1; j++)
		(*L).data[j] = (*L).data[j+1];
	(*L).length--;
	return OK;
}
int _tmain(int argc, _TCHAR* argv[])
{
	SqList L; L.length = 0;
	tailAdd(&L, 2); tailAdd(&L,3); tailAdd(&L, 4); tailAdd(&L, 5);
	return 0;
}


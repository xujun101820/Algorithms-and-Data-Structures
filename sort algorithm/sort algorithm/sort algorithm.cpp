// sort algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;
char *getABC()
{
	char str[10];
//	strcpy(str, "12345");
	return str;
}
///(1)交换排序：冒泡排序+快速排序////////////////////////////////////
//1，冒泡排序
void bubble_sort(int *unsorted,int n)
{
	for (int i = 0; i <n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (unsorted[j] > unsorted[j + 1])
			{
				int temp = unsorted[j];
				unsorted[j] = unsorted[j + 1];
				unsorted[j + 1] = temp;
			}
		}
	}
}
//2，快速排序
void quicksort(int data[], int left, int right)
{
	int key = data[right];
	if (left < right)
	{
		int i = left; int j = right;
		while (i < j)
		{
			while (i < j&&data[i] <= key)
			{
				i++;
			}
			data[j] = data[i];
			while (i < j&&data[j] >= key)
			{
				j--;
			}
			data[i] = data[j];
		}
		data[i] = key;
		quicksort(data, left, i - 1);
		quicksort(data, i + 1, right);
	}
}
//(2)插入排序///////////////////////////////////////////////////////
//1，for循环版本
void Insert_Sort(int *unsorted,int n)
{
	for (int i = 1; i < n ; i++)
	{
		int j = i-1;
		int temp = unsorted[i];
		while (j>=0 && temp< unsorted[j])
		{
			unsorted[j + 1] = unsorted[j];
			j--;
		}
		unsorted[j + 1] = temp;
	}
}
//2,递归版本
void Insert_Sort_d(int *unsorted, int n)
{
	if (n > 1)
		Insert_Sort_d(unsorted, n - 1);
	int temp = unsorted[n-1];
	int j = n - 1 - 1;
	while (j >= 0 && temp< unsorted[j])
	{
		unsorted[j + 1] = unsorted[j];
		j--;
	}
	unsorted[j + 1] = temp;
}
//3 希尔排序
void Shell_Sort(int *unsorted, int n)
{
	int step = n / 2;
	while (step >= 1)
	{
		for (int i = step; i < n; i++)
		{
			int temp = unsorted[i];
			int j = i - step;
			while (j >= 0 && temp< unsorted[j])
			{
				unsorted[j + step] = unsorted[j];
				j=j-step;
			}
			unsorted[j + step] = temp;
		}
		step = step / 2;
	}
}
//(3)选择排序///////////////////////////////////////////////////////
void Selection_Sort(int *unsorted, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (unsorted[j] < unsorted[min])
				min = j;
		}
		int temp = unsorted[i];
		unsorted[i] = unsorted[min];
		unsorted[min] = temp;
	}
}
//(4)归并排序///////////////////////////////////////////////////////
void merge(int *unsorted, int start, int m, int end)
{
	int *left = new int[m-start+2];
	int *right = new int[end-m+1];
	for (int i = start; i <= end; i++)
	{
		if (i <= m)
			left[i-start] = unsorted[i];
		else
			right[i - m - 1] = unsorted[i];
	}
	int p = 0; int q = 0;
	left[m - start + 1] = 999999;
	right[end - m] = 999999;
	for (int i = start; i <= end; i++)
	{
		if (left[p] < right[q])
		{
			unsorted[i] = left[p];
			++p;
		}
		else
		{
			unsorted[i] = right[q];
			++q;
		}
	}
}
void Recursive_Sort(int *unsorted, int start,int end)
{
	if (end > start)
	{
		int m = (start + end) / 2;
		Recursive_Sort(unsorted, start, m);
		Recursive_Sort(unsorted, m + 1, end);
		merge(unsorted, start, m, end);
	}
}
//(5)堆排序属于选择排序///////////////////////////////////////////////////////
void max_Heapify(int *unsorted, int parent, int n)
{
	int temp = unsorted[parent];
	int child_left = parent * 2 + 1;
	int child_right = child_left + 1;
	int largest = parent;
	if (child_left<n&&unsorted[child_left]>unsorted[parent])
		largest = child_left;
	if (child_right<n&&unsorted[child_right]>unsorted[largest])
		largest = child_right;
	if (largest != parent)
	{
		int temp = unsorted[largest];   //较大的节点值将交换到其所在节点的父节点
		unsorted[largest] = unsorted[parent];
		unsorted[parent] = temp;

		max_Heapify(unsorted, largest, n); //递归遍历

	}
}
void build_max_Heap(int *unsorted, int n)
{
	int len = n;
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		max_Heapify(unsorted, i, len);     //建立最大堆，将堆中最大的值交换到根节点  
	}
}
void HeapSort(int *unsorted, int n)
{
	build_max_Heap(unsorted, n);
	for (int i = n - 1; i >= 0; --i)
	{
		int temp = unsorted[0];
		unsorted[0] = unsorted[i];
		unsorted[i] = temp;
		max_Heapify(unsorted,0,i);
	}
}
//(6)计数排序///////////////////////////////////////////////////////
void CountSort(int *A, int *B, int array_size, int k)
{
	int *C = new int[k + 1];
	int i, value, pos;
	for (i = 0; i <= k; i++)
	{
		C[i] = 0;
	}
	for (i = 0; i< array_size; i++)
	{
		C[A[i]] ++;
	}
	for (i = 1; i <= k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (i = array_size - 1; i >= 0; i--)
	{
		value = A[i];
		pos = C[value];
		B[pos - 1] = value;
		C[value]--;
	}
}
//(7)基数排序///////////////////////////////////////////////////////
int main()
{
	int a[] = {1,2,3,7,5,3,2,1,6,8,5};
	int b[11];
	//bubble_sort(a,11);
	//Insert_Sort_d(a, 11);
	//Selection_Sort(a,11);
	//Shell_Sort(a,11);
	//merge(a, 0,0,1);
	//int l = 999999;
	//Recursive_Sort(a, 0,10);
	//HeapSort(a, 11);
	CountSort(a, b, 11, 8);
	/*char *p = getABC();
	cout << p;*/
	return 0;
}


// tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;
struct BinaryTreeNode
{
	int m_value;
	BinaryTreeNode * p_left;
	BinaryTreeNode * p_right;
};
BinaryTreeNode * constructCore(int *startpreorder, int *endpreorder, int *startmidorder, int *endmidorder)
{
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_value = startpreorder[0]; root->p_left = root->p_right = NULL;
	if (startpreorder == endpreorder)
	{
		if (startmidorder == endmidorder&&*startmidorder == *startpreorder)
		{
			return root;
		}
		else
		{
			throw std::exception("Invalid input");
		}
	}
	int *rootmidorder=startmidorder;
	while (rootmidorder <= endmidorder&&*rootmidorder != root->m_value)
	{
		++rootmidorder;
	}
	if (rootmidorder == endmidorder&&*rootmidorder != root->m_value)
		throw std::exception("Invalid input");

	int leftLength = rootmidorder - startmidorder;
	if (leftLength>0)
		root->p_left = constructCore(startpreorder + 1, startpreorder + leftLength, startmidorder, startmidorder + leftLength - 1);
	if (leftLength<endmidorder - startmidorder)
		root->p_right = constructCore(startpreorder + leftLength + 1, endpreorder, startmidorder + leftLength + 1, endmidorder);
	return root;
}
void preorderTraversal(BinaryTreeNode *head)
{
	if (head == NULL) cout << "empty" << endl;
	else
	{
		cout << head->m_value << " ";
		if (head->p_left!=NULL)
		preorderTraversal(head->p_left);
		if (head->p_right != NULL)
		preorderTraversal(head->p_right);
	}
}
void midorderTraversal(BinaryTreeNode *head)
{
	if (head == NULL) cout << "empty" << endl;
	else
	{
		if (head->p_left != NULL)
			midorderTraversal(head->p_left);

		cout << head->m_value << " ";

		if (head->p_right != NULL)
			midorderTraversal(head->p_right);
	}
}
void postorderTraversal(BinaryTreeNode *head)
{
	if (head == NULL) cout << "empty" << endl;
	else
	{
		if (head->p_left != NULL)
			postorderTraversal(head->p_left);

		if (head->p_right != NULL)
			postorderTraversal(head->p_right);

		cout << head->m_value << " ";
	}
}
BinaryTreeNode * construct(int *preorder,int *midorder,int length)
{
	if (preorder == NULL || midorder == NULL || length <= 0) return 0;

	return constructCore(preorder, preorder + length - 1, midorder, midorder+length-1);
}
int getDeep(BinaryTreeNode *head)
{
	int left,right;
	if (head == NULL) return 0;
	else
	{
		left = getDeep(head->p_left);
		right = getDeep(head->p_right);
		return left > right ? left + 1 : right + 1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode *p = construct(a, b, 8);
	preorderTraversal(p); cout << endl;
	midorderTraversal(p); cout << endl;
	postorderTraversal(p); cout << endl;
	cout << getDeep(p) << endl;
	return 0;
}


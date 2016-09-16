// find_in_matric.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

bool find_or_not(int mat[][4], int row, int col, int target)
{
	int i=0,j;
	while (true)
	{
		for (j = col - 1; j >= 0; j--)
		{
			if (target == mat[i][j]) return true;
			if (target > mat[i][j])break;
		}
		if (j < 0) return false;
		for (; i < row; i++)
		{
			if (target == mat[i][j]) return true;
			if (target < mat[i][j])break;
		}
		if (i == row) return false;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int mat[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, {4,7,10,13}, {6,8,11,15} };
	bool re = find_or_not(mat,4,4,3);
	return 0;
}


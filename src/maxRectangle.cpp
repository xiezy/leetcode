#include<vector>
#include<iostream>
#include<iomanip>

using namespace std;

// given a 2-D matrix of integers, find the largest submatrix with maximum sum

int maxthree(int a, int b, int c)
{
	int maxab = a > b ? a : b;
	return maxab > c ? maxab : c;
}

int maxSubMatrix(vector<vector<int> > &matrix)
{

}

/*
int maxSubMatrix(vector<vector<int> > &matrix)
{
	if (matrix.size() == 0|| matrix[0].size() == 0) 
		return 0;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			cout << setw(4) << matrix[i][j] << ',';
		}
		cout << endl;
	}
cout << endl;
  vector<int> row(matrix[0].size(), 0);
	vector<vector<int> > corner(matrix.size(), row);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (i==0 && j==0)
			{
				corner[i][j] = matrix[0][0];
				continue;
			}
			int top = INT_MIN, left = INT_MIN, lefttop = INT_MIN;
			if (i > 0)
			{
				top = corner[i-1][j];
			}
			if (j > 0)
				left = corner[i][j-1];
			if (i > 0 && j > 0 )
				lefttop = corner[i-1][j-1];
			corner[i][j] = maxthree(top, left, lefttop) + matrix[i][j];
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			cout << setw(4) << corner[i][j] << ',';
		}
		cout << endl;
	}
	int max = 0;
	for (int i = 0; i < matrix.size() - 1; ++i)
	{
		for (int j = 0; j < matrix[0].size() - 1; ++j)
		{
			for (int p = i+1; p < matrix.size(); ++p)
			{
				for (int q = j + 1; q < matrix[0].size(); ++q)
				{
					if (corner[p][q] - corner[i][j] > max)
					{
						max = corner[p][q] - corner[i][j];
						cout << "found max at " << i << ' ' << j << ' ' << p << ' ' << q << ' ' << max << endl;
					}
				}
			}
		}
	}
	return max;
}********/

int main()
{
	vector<vector<int> > matrix;
	int a[] = {1,	2, -1, -4, -20};
	vector<int> row(a, a+sizeof(a)/sizeof(int));
	matrix.push_back(row);
	int b[] = {-8, -3, 4, 2, 1};
	vector<int> row2(b, b+sizeof(b)/sizeof(int));
	matrix.push_back(row2);
  int c[] = {3, 8, 10, 1, 3};
 	vector<int> row3(c, c+sizeof(c)/sizeof(int));
  matrix.push_back(row3);
	int d[] = {-4, -1, 1, 7, -6};
	vector<int> row4(d, d+sizeof(d)/sizeof(int));
	matrix.push_back(row4);
  cout << maxSubMatrix(matrix) << endl ;
}

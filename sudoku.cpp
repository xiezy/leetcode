#include<vector>
#include<cctype>
#include<string>
#include<iostream>

using namespace std;
    bool isValid(vector<vector<char> > &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (i == row)
                continue;
            if (board[i][col] == c)
                return false;
        }
        for (int j = 0; j < 9; ++j)
        {
            if (j == col)
                continue;
            if (board[row][j] == c)
                return false;
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
						{
                int x = (row/3)*3 + i, y = (col/3)*3+j;
                if (x == row && y == col)
                    continue;
                if (board[x][y] == c)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char> > &board, int row, int col)
    {
        bool found = false;
        for (int i = row; i < 9 && !found; ++i)
        {
            for (int j = 0; j < 9 && !found; ++j)
            {
								if (i == row && j < col)
									continue;
                if (!isdigit(board[i][j]))
								{
										found = true;
                    break;
								}
            }
        }
			if (!found)
			{
				return true;
      }
			for (int i = row; i < 9; ++i)
			{
				for (int j = 0; j < 9; ++j)
				{
					if (i == row && j < col)
						continue;
					if (isdigit(board[i][j]))	
						continue;
					// i, j is empty
					for (char c = '1'; c <= '9'; ++c)
					{
						if (isValid(board,i,j,c))
						{
							board[i][j] = c;
							bool ret = solve(board, i, j);
							if (ret == true)
							{
								return ret;
							}
						}
					}
          board[i][j] = '.';
					return false;
				}
			}
      return false;
    }
int main()
{
  char* arr[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	vector<vector<char> > board;
	for (int i = 0; i < 9; ++i)
	{
		vector<char> row(arr[i], arr[i] + sizeof(arr[i])/sizeof(char));
		board.push_back(row);
	}
	cout << solve(board, 0,0) << endl;
	for (int  i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout << board[i][j] << ',';
		cout << endl;
	}
	
}

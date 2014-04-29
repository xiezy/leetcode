#include<iostream>
#include<vector>
#include<string>

using namespace std;

    bool isValid(vector<int> &board, int cur, int row)
    {
        for (int i = 0; i < cur; ++i)
        {
            if (board[i] == row || abs(board[i] - row) == cur - i)
                return false;
        }
        return true;
    }
    vector<string> print(vector<int> &board)
    {
        vector<string> ret;
        for (int i = 0; i < board.size(); ++i)
        {
            string str;
            for (int j = 0; j < board.size(); ++j)
            {
                if (j != board[i])
                    str.append(1,'.');
                else
                    str.append(1,'Q');
            }
            ret.push_back(str);
        }
        return ret;
    }
    vector<vector<string> > solve(vector<int> &board, int cur)
    {
        vector<vector<string> > ret;
        if (cur == board.size())
        {
            ret.push_back(print(board));
            return ret;
        }
        for (int i = 0; i < board.size(); ++i)
        {
            if (isValid(board, cur, i))
            {
                board[cur] = i;
                vector<vector<string> > sol = solve(board, cur+1);
            		for(int j = 0; j < sol.size(); ++j)
            		{
               	 	ret.push_back(sol[j]);
            		}
            }
        }
        return ret;
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<int> board(n,0);
        return solve(board, 0);
    }
int main()
{
	int n;
	cin >> n;
	vector<vector<string> > sol = solveNQueens(n);
	for (int i = 0; i < sol.size(); ++i)
	{
		for (int j = 0; j < sol[i].size(); ++j)
		{
			cout << sol[i][j] << endl;
		}
		cout << endl;
	}
}

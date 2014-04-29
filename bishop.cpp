#include<vector>
#include<iostream>
using namespace std;

/*
// board has some locatons set
int findNext(vector<vector<int> > &board)
{
    if (board.size() == 0 || board[0].size() == 0)
        return 0;
    vector<vector<int> > copy(board);
    for (int i = 0; i < board.size(); ++i )
    {
       for (int j = 0; j < board[i].size(); ++j)
       {
           if (board[i][j] == 1)
           {
               for (int k = -n; k <=n; k++) { 
                   if ( i+k >= 0 && i +k < n && j+k >= 0 && j +k < n)
                       copy[i+k][j+k] = 1;               
               }
            }
       }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
				{
					if (copy[i][j] == 0)
					{
						board[i][j] = 1;
						return 1;
					}
				}
		return 0;
}
*/


/*
     print a valid placement of bishops
 */
void print(vector<vector<int> > &board)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			// avoid print ',' at the end of the row
			if (j != board[i].size() - 1)
				cout << board[i][j] << ',';
			else 
				cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

/*
 *  isValid tests if location (i,j) conflicts with existing selected locations
 *  param: 	selected - two dimentional vector storing the already picked locations
 *					i - row index of the tentative location
 *					j - col index of the tentative location
 *  return: a boolean indicating whether we can add the new location (i,j)
 */
bool isValid(vector<vector<int> > &selected, int i, int j)
{
	int n = selected.size();
	for (int k = -n; k <=n; k++) { 
		// test all potential diagnol locations
		if ( (i+k >= 0 && i +k < n && j+k >= 0 && j +k < n && selected[i+k][j+k] == 1) ||
				(i+k >= 0 && i + k < n && j-k >=0 && j-k <n && selected[i+k][j-k] == 1))
			return false;
	}
	return true;
}

/*
 *  bishopHelp is a recursive function that tests all unvisited locations and 
 *  attempt to add each location to see if we can form a solution of input (n,k)
 *  param:  selected - matrix that contains already picked locations
 *  				row - row index that we visited earlier
 * 					col - col index that we visited earlier
 * 					cur - the number of bishops we have placed
 * 					k   - the total number of bishops we need to place
 *  return: total number of placements within the remaining unvisited locations
 */

int bishopHelp(vector<vector<int> > &selected, int row, int col, int cur, int k)
{
	int total = 0;
  // since cur is the number of bishops we have placed, if cur is equal to k, meaning 
  // we have reached a solution
	if (cur == k)
	{
		print(selected);
		return 1;
	}
	else
	{
		// the use of row and col as parameter allows us to avoid visiting same locations 
    // that have been picked already
		for (int i = row; i < selected.size(); ++i)
		{
			for (int j = 0; j < selected.size(); ++j)
			{
				// skip locations that have been visited already
				if ((i == row && j <= col) || selected[i][j] == 1)
					continue;
				// if (i, j) is compatible with existing bishops
				if (isValid(selected, i, j))
				{
				// mark the bishop on the board
					selected[i][j] = 1;
				// attempt to place the remaining bishops, if we succeed at the next level, 
				// increment the count
					total += bishopHelp(selected, i, j, cur+1, k);
				// we are done with this location, restore the board
					selected[i][j] = 0;
				}
			}
		}
	}
	return total;
}

/* 
 *  bishops returns the number of possible placements for k bishops on a board of size n
 *  param: n - board size
 *    		 k - number of bishops to place
 *  return: total number of possible placements
 */ 
int bishops(int n, int k) {
		if (n <= 0) return 0;
    int total = 0;
		//initialize selected to be a n*n matrix with all 0 elements
		vector<int> row(n,0);
		vector<vector<int> > board(n, row);
		total = bishopHelp(board, 0, -1, 0, k);
		return total;
}

int main()
{
	cout << "please the matrix size (n) and number of bishops to place (k) " << endl;
	int n, k;
	cin >> n >> k;
	cout << bishops(n, k) << endl;
}

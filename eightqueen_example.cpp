#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
 
    vector<vector<string> > res;
     
    void printres(vector<int> A,int n){
        vector<string> r;
        for(int i=0;i<n;i++){
            string str(n,'.');
            str[A[i]]='Q';
            r.push_back(str);
        }
        res.push_back(r);
    }
     
     
    bool isValid(vector<int> A, int r){
        for (int i=0;i<r;i++){
    //        if ( (A[i]==A[r])||(abs(A[i]-A[r])==(r-i))){
            if ( (abs(A[i]-A[r])==(r-i))){
                return false;
            }
        }
        return true;
    }
     
    void nqueens(vector<int> A, int cur, int n){
        if (cur==n){printres(A,n);}
        else{
            for (int i=0;i<n;i++){
                A[cur]=i;
                if (isValid(A,cur)){
                    nqueens(A,cur+1,n);
                }
            }
        }
    }
      
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        vector<int> A(n,-1);
        nqueens(A,0,n);
        return res;
    }
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	vector<vector<string> > sol = s.solveNQueens(n);
	for (int i = 0; i < sol.size(); ++i)
	{
		for (int j = 0; j < sol[i].size(); ++j)
			cout << sol[i][j] << endl;
		cout << endl;
	}
}

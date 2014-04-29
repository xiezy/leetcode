#include<vector>
#include<iostream>
#include<set>
using namespace std;
set<vector<int> > solve(int *cand, int n, int target);
/*    set<vector<int> > solve(vector<int> &cand, int target);

    vector<vector<int> > combinationSum(vector<int> &cand, int target) {
        vector<vector<int> > ret;
        if (cand.size() == 0 || target < 0)
            return ret;
        set<vector<int> > sol = solve(cand,target);
        for (auto it = sol.begin(); it != sol.end(); ++it)
        {
            vector<int> v = *it;
            sort(v.begin(), v.end());
            ret.push_back(v);
        }
        return ret;
    }
    set<vector<int> > solve(vector<int> &cand, int target)
    {
        set<vector<int> > ret;
        for (int i = 0; i < cand.size(); ++i)
        {
            if (cand[i] == target)
            {
                vector<int> s(1, target);
                ret.insert(s);
            }
            else if (cand[i] < target)
            {
                set<vector<int> > s = solve(cand, target - cand[i]);
                for (auto it = s.begin(); it != s.end(); ++it)
                {
                    vector<int> v = *it;
                    v.push_back(cand[i]);
                    ret.insert(v);
                }
            }
        }
        return ret;
    }
*/
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if (num.size() == 0 || target < 0)
            return ret;
        int *cand = new int[num.size()];
        for (int i = 0; i < num.size(); ++i)
	cand[i] = num[i];
        set<vector<int> > sol = solve(cand, num.size(), target);
        for (auto it = sol.begin(); it != sol.end(); ++it)
        {
            vector<int> v = *it;
            ret.push_back(v);
        }
        return ret;
    }
    set<vector<int> > solve(int *cand, int n, int target)
    {
        set<vector<int> > ret;
        if (n == 0 || target < 0)
            return ret;
        for (int i = 0; i < n; ++i)
        {
            if (cand[i] == target)
            {
                vector<int> s(1, target);
                ret.insert(s);
            }
            else if (cand[i] == 0)
            {
                continue;
            }
            else if (cand[i] < target)
            {
                int val = cand[i];
                cand[i] = 0;
                set<vector<int> > s = solve(cand, n, target - val);
                for (auto it = s.begin(); it != s.end(); ++it)
                {
                    vector<int> v = *it;
                    v.push_back(val);
                    sort(v.begin(), v.end());
                    ret.insert(v);
                }
                cand[i] = val;
            }
        }
        return ret;
          
    }
int main()
{
  //int a[]={27,34,37,31,48,35,39,41,20,36,49,32,25,40,22,43,29,45,44,42,38,26,30,47,23};
  int a[]={1,2,4,1,2,2,5,4,4,3,1};
  vector<int> vec(a,a+sizeof(a)/sizeof(int));
  vector<vector<int> > sol = combinationSum2(vec, 4);
  for (int i = 0; i < sol.size(); ++i)
  {
    for (int j = 0; j < sol[i].size(); ++j)
      cout << sol[i][j] << ',';
    cout << endl;
  }
}

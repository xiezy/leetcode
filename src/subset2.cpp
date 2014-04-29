#include<vector>
#include<iostream>

using namespace std;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> emp;
        ret.push_back(emp);
        if (S.size() == 0)
            return ret;
        vector<int> minus = S;
        int dup = 0;
        for (dup = 0; dup < S.size(); ++dup)
        {
            if (S[dup] != S[0])
            {
                break;
            }
        }
        cout << "dup = " << dup << endl;
        if (dup == S.size())
            minus.clear();
        else
            minus.erase(minus.begin(), minus.begin() + dup);
        cout << "minus size = " << minus.size() << endl;
        vector<vector<int> >sol = subsetsWithDup(minus);
        ret = sol;
        for (int j = 1; j <= dup; ++j)
        {
            for (int i = 0; i < sol.size(); ++i)
            {
                vector<int> num = sol[i];
                num.insert(num.begin(),j,S[0]);
                sort(num.begin(), num.end());
                ret.push_back(num);
            }
        }
        return ret;
    }
int main()
{
  vector<int> v(1,0);
  subsetsWithDup(v);
}

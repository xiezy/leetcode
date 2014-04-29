#include<iostream>
#include<unordered_set>
#include<vector>
#include<set>
using namespace std;
      vector<vector<int> > twoSum(vector<int> &numbers, int target, int skip) {
        vector<vector<int> > ret;
        unordered_set<int> seen;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (i == skip) continue;
            if (seen.find(target - numbers[i]) != seen.end())
            {
                vector<int> row;
                row.push_back(target - numbers[i]);
                row.push_back(numbers[i]);
                row.push_back(-target);
                sort(row.begin(), row.end());
                ret.push_back(row);
//                return ret;
            }
            else
            {
                seen.insert(numbers[i]);
            }
        }
        return ret;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        set<vector<int> > sol;
        for (int i = 0; i < num.size(); ++i)
        {
            vector<vector<int> > s = twoSum(num, -num[i], i);
            for (int j = 0; j < s.size(); ++j)
            {
                vector<int> row = s[j];
//                row.push_back(num[i]);
//                sort(row.begin(), row.end());
                sol.insert(row);
            }
        }
	cout << "here" << endl;
        for (set<vector<int> >::iterator it = sol.begin(); it != sol.end(); ++it)
        {
            ret.push_back(*it);
        }
        return ret;
      }
int main()
{
    vector<int> num(3,0);
    threeSum(num);
}

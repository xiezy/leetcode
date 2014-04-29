#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

    int perm(int n);
    int getKthnRm(set<int> &s, int k);
    string getPermutation(int n, int k) {
        k--;
        // convert to 0 based
        set<int> remain;
        for (int i = 1; i <= n; ++i)
            remain.insert(i);
        string ret;
        int size = n;
        while (k > 0)
        {
            size = remain.size();
            int bucket = perm(size-1);
            int toRmv = k/bucket;
            int val = getKthnRm(remain, toRmv);
            ret.append(1,val+'0');
            k = k % bucket;
        }
        for (set<int>::iterator it = remain.begin(); it!= remain.end(); ++it)
        ret.append(1,*it + '0');
        return ret;
    }
    // k is 0 based?
    int getKthnRm(set<int> &s, int k)
    {
        int ret=0;
        set<int>::iterator it = s.begin();
        for (int i = 0; i < k; ++i)
        {
            it++;
        }
        ret = *it;
        s.erase(it);
        return ret;
    }
    int perm(int n)
    {
        if (n <= 1)
            return 1;
        return n*perm(n-1);
    }
int main()
{
  int n,k;
  cout << "enter n and k" << endl;
  cin >> n >> k;
  cout << getPermutation(n,k) << endl;
}

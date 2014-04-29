#include<iostream>
#include<vector>
using namespace std;
    vector<int> getHighest(int n)
    {
        vector<int> ret(2,0);
        ret[0] = n; 
        ret[1] = 1;
        if (n < 10) {
            ret[1] = n;
            return ret;
        }
        while (ret[0] >= 10)
        {
            ret[0]/=10;
            ret[1]*=10;
        }
        ret[1] *= ret[0];
        return ret;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        while (x >= 10)
        {
cout << x << endl;
            vector<int> v = getHighest(x);
            if (v[0] != x % 10)
                return false;
            x -= v[1];
while (x%10 == 0)
            x/=10;
        }
        return true;
    }
int main()
{
  cout << isPalindrome(121) << endl;
}

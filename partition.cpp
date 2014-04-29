#include<vector>
#include<string>
using namespace std;
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.length()/2; ++i)
        {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ret;
        if (s.length() == 0) return ret;
        for (int i = 1; i <= s.length(); ++i)
        {
            string firstHalf = s.substr(0, i);
            string secondHalf = s.substr(i, s.length() - i);
            if (isPalindrome(firstHalf))
            {
                if (secondHalf.length() <= 1)
                {
                    vector<string> v(1,firstHalf);
                    ret.push_back(v);
                }
                else
                {
                    vector<vector<string> > sol = partition(secondHalf);
                    for (int j = 0; j < sol.size(); ++j)
                    {
                        vector<string> v = sol[j];
                        v.push_back(firstHalf);
                        ret.push_back(v);
                    }
                }
            }
        }
        return ret;
    }
int main()
{
  partition("a");
}

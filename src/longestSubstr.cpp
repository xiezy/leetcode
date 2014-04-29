#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            unordered_set<char> hs;
            int len = 0;
            while (i+len < s.length())
            {
                if (hs.find(s[i+len]) != hs.end())
                {
                    break;
                }
                else
                {
                    hs.insert(s[i+len]);
                }
                len++;
            }
            if (len > max)
                max = len;
        }
        return max;
    }

int main()
{
  cout << lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;
}

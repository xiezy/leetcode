#include<iostream>
#include<unordered_set>
#include<set>
#include<string>

using namespace std;
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.length() == 0) return false;
        set<string> words;
        for ( auto it = dict.begin(); it != dict.end(); ++it )
        {
            words.insert(*it);
        }
        return find(s, words);
    }
    bool find(string s, set<string> & words)
    {
        for (set<string>::reverse_iterator it = words.rbegin(); it != words.rend(); ++it)
        {
            if (s == *it) return true;
            if (s.find(*it) == 0)
            {
                if(true == find(s.substr(it->length(), s.length() - it->length()), words))
                    return true;
            }
        }
        return false;
    }
int main()
{
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
}

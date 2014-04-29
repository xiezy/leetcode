#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        vector<vector<string> > table(s.length()+1, ret);
        vector<string> tmp(1,"");
        table[0]=tmp;
        for (int i = 0; i <= s.length(); ++i)
        {
            if (table[i].size() == 0)
                continue;
            for (auto it = dict.begin(); it != dict.end(); ++it)
            {
                if (s.find(*it) == 0 && i + it-> length() <= s.length())
                {
                    for (int j = 0; j < table[i].size(); ++j)
                    {
                        string str = table[i][j];
                        str.append(*it);
                        str.append(" ");
                        table[i+it->length()].push_back(str);
                    }
                }
            }
        }
        return table[s.length()];
    }
int main()
{
	string s = "catsanddog";
	unordered_set<string> ss;
	ss.insert("cat");
	ss.insert("cats");
	ss.insert("and");
	ss.insert("sand");
	ss.insert("dog");
	vector<string> ret = wordBreak(s, ss);
	for (int i = 0; i < ret.size(); ++i)
		cout << ret[i] << endl;
}

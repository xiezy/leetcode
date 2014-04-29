#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;
    vector<int> findSubstring(string str, vector<string> &words) {
        vector<int> ret;
        if (str.length() == 0 || words.size() == 0)
        {
            ret.push_back(0);
            return ret;
        }
        unordered_map<string, int > loc;
        for (int i = 0; i < words.size(); ++i)
        {
            if (loc.find(words[i])!=loc.end())
                loc[words[i]]++;
            else 
                loc[words[i]] = 1;
        }
        int width = words[0].length();
        for (int i = 0; i < str.length() - width*words.size() + 1; ++i)
        {
            bool mismatch = false;
        	//	cout << "checking index: " << i << endl;
				    unordered_map<string, int> copy(loc);
            for (int j = 0; j < words.size(); ++j)
            {
                string scan = str.substr(i+j*width, width);
                if (copy.find(scan) == copy.end())
                {
						//			cout << "mismatch found at index: " << i+j*width
                    mismatch = true;
                    break;
                }
                else
                {
                    copy[scan]--;
                }
                if (copy[scan] == 0)
                {
                    copy.erase(scan);
                }
            }
            if (!mismatch)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
int main()
{
	string str = "barfoothefoobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	vector<int> ret = findSubstring(str, words);
	for (int i = 0; i < ret.size(); ++i)
		cout << ret[i] << ',';
	cout <<endl;

}

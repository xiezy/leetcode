#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>

using namespace std;
    vector<string> changeone(unordered_set<string> &dict, string word)
    {
        vector<string> ret;
        for (int i = 0; i < word.length(); ++i)
        {
            string copy = word;
            for (int j = 0; j < 26; ++j)
            {
                copy[i] = 'a' + j;
                if (word[i] != j + 'a')
                {
                    if (dict.find(copy) != dict.end())
                    {
                        ret.push_back(copy);
                    }
                }
            }
        }
        return ret;
    }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        unordered_map<string, string> visited; 
        q.push(start);
        q.push("");
        vector<vector<string> > ret;
        visited[start] = start;
        while (!q.empty())
        {
            string cur = q.front();
            q.pop();
cout << "exmaing " << cur << endl;
/*            if (cur == end)
            {
                vector<string> sol;
                while (cur != start)
                {
                    sol.insert(sol.begin(), cur);
                    cur = visited[cur];
                }
                sol.insert(sol.begin(), start);
                ret.push_back(sol);
                visited.erase(end);
for (unordered_map<string, string>::iterator it = visited.begin(); it != visited.end(); ++it)
	cout << it->first << ' ' << it->second << endl;
                continue;
            }
*/
            if (cur == "")
            {
cout << "sentinel" << endl;
                if (!q.empty())
                {
                    q.push("");
                //    ret++;
                }
                continue;
            }
            vector<string> nbor = changeone(dict, cur);
            for (int i = 0; i < nbor.size(); ++i)
            {
                if (visited.find(nbor[i]) == visited.end())
                {
							  	if (nbor[i] == end)
									{
cout << "found a mtach from " << cur << endl;
											vector<string> sol;
											string curr = nbor[i];
											while (curr != start)
											{
													sol.insert(sol.begin(), curr);
													curr = visited[curr];
											}
						  				sol.insert(sol.begin(), start);
											ret.push_back(sol);
									//		visited.erase(end);
											continue;
									}
									else
									{
                    q.push(nbor[i]);
                    visited[nbor[i]] = cur;
									}
                }
else
{
	cout << "skipping " << nbor[i] << " because of " << visited[nbor[i]] << endl;
}
            }
        }
        return ret;
    }

int main()
{
	string start = "hot", end = "dog";
  string d[] = {"hot","cog","dog","tot","hog","hop","pot","dot"};
  unordered_set<string> dict (d, d+8);
	vector<vector<string> > ret = findLadders(start, end, dict);
	for (int i = 0; i < ret.size(); ++i)
	{
		for (int j = 0; j < ret[i].size(); ++j)
		{
		cout << ret[i][j] << "->";
		}
		cout << endl;
	}
}

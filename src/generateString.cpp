#include<string>
#include<vector>
#include<iostream>
using namespace std;

// 一个string由0，1和？组成，并且？可以被替换成0或者1，让输出所有的把？替换之后不同的string，比如1？0把？替换之后能够生成110和100

vector<string> generate(string str)
{
  vector<string> ret;
  if (str.length() == 0) return ret;
  int ind = -1;
  for (int i = 0; i < str.length(); ++i)
  {
    if (str[i] == '?')
    {
      ind = i;
      break;
    }
  }
  if (ind == -1)
  {
    ret.push_back(str);
    return ret;
  }
  vector<string> sol = generate(str.substr(ind+1, str.length() - ind - 1));
  if (sol.size() == 0)
  {
    str[str.length() - 1] = '0';
    ret.push_back(str);
    str[str.length() - 1] = '1';
    ret.push_back(str);
    return ret;
  }
  for (int i = 0; i < sol.size(); ++i)
  {
    string tmp = sol[i];
    tmp.insert(0,1,'0');
    tmp.insert(0,str.substr(0,ind));
    ret.push_back(tmp);
    tmp[ind] = '1';
    ret.push_back(tmp);
  }
  return ret;
}

int main()
{
  string str = "01?01?111???0";
  vector<string> vec = generate(str);
  for (int i = 0; i < vec.size(); ++i)
  {
    cout << vec[i] << endl;
  }
}

#include<vector>
#include<string>
#include<iostream>
using namespace std;
vector<string> validString(int n)
{
  vector<string> ret;
  if (n == 0) return ret;
  else if (n == 1)
  {
    ret.push_back("A");
    ret.push_back("B");
    ret.push_back("C");
    return ret;
  }
  else if (n == 2)
  {
    vector<string> sol = validString(n-1);
    for (int i = 0; i < sol.size(); ++i)
    {
      ret.push_back("A"+sol[i]);
      ret.push_back("B"+sol[i]);
      ret.push_back("C"+sol[i]);
    }
    return ret;
  }
  else // n >= 3 , n-1>=2
  {
    vector<string> sol = validString(n-1);
    for (int i = 0; i < sol.size(); ++i)
    {
      if (sol[i][0] == sol[i][1])
      {
        ret.push_back("A"+sol[i]);
        ret.push_back("B"+sol[i]);
        ret.push_back("C"+sol[i]);
      }
      else
      {
        ret.push_back(sol[i][0] + sol[i]);
        ret.push_back(sol[i][1] + sol[i]);
      }
    }
    return ret;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<string> sol = validString(n);
  for (int i = 0; i < sol.size(); ++i)
  {
    cout << sol[i] << endl;
  }
  vector<int> x(n+1,0), y(n+1,0);
  x[1] = 3, y[1] = 3;
  x[2] = 6, y[2] = 3;
  for (int i = 3; i <= n; ++i)
  {
    x[i] = x[n-1] + y[n-1];
    y[i] = 2*x[n-1] + y[n-1];
  }
  cout << x[n] + y[n] << endl;
}
